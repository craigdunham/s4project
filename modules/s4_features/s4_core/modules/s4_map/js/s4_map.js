(function($) {
	Drupal.behaviors.s4Map = {

		attach : function() {
			if ($('#site-map').length) {
				s4Map.init($('#site-map'));
			}
			if ($('#site-view-map').length) {
				s4Map.init($('#site-view-map'));
				var bounds = new google.maps.LatLngBounds();
				$.each(Drupal.settings.s4_map_site_coordinates, function(index, marker) {
				  s4Map.addMarker(marker.lat, marker.lon, marker.name);
	  			bounds.extend(new google.maps.LatLng(marker.lat, marker.lon));
				});
				s4Map.map.fitBounds(bounds);
			}
		}
	};

	var s4Map = {
		
		map : null,
		
		activeInfoWindow : null,
		
		markers : [ ],
		
		mapElement : { },
		
		style : [ ],
		
		lastZoom : 10,
		
		zoomStorage : [ ],
		
		zoomDivider : .4,
		
		maxSize: 70,
		
		minSize: 10,
		
		init : function(element) {
			s4Map.lastZoom = Drupal.settings.s4_map.zoom;
			this.element = element;
			var center = new google.maps.LatLng(Drupal.settings.s4_map.lat, Drupal.settings.s4_map.lon);
			s4Map.map = new google.maps.Map(element.get(0),
	        				   {'center' : center,
								'zoom' : Drupal.settings.s4_map.zoom,
							    mapTypeId: google.maps.MapTypeId.TERRAIN
							    });
			
			if (this.element.hasClass('autofill')) {
				google.maps.event.addListener(s4Map.map, 'idle', s4Map.reloadMap);
			}
		},
		
		setCenter : function(lat, lon) {
			var newCenter = new google.maps.LatLng(lat, lon);
			s4Map.map.setCenter(newCenter);
			s4Map.map.setZoom(15);
		},
		
		reloadMap : function(event) {
			var boundaries = s4Map.map.getBounds();
			if (boundaries === undefined) {
				return null;
			}
			$('#map-loading-indicator').show();
			var program = (Drupal.settings.s4_map_program)
			              ? '/' + Drupal.settings.s4_map_program
			              : '';
			$.getJSON(Drupal.settings.basePath + 'json/map/sites' + program + '?lat_min=' + boundaries.getSouthWest().lat() +'&lat_max=' + boundaries.getNorthEast().lat() + '&lon_min=' + boundaries.getSouthWest().lng() + '&lon_max=' + boundaries.getNorthEast().lng() ,function(data) {
				$.each(data.nodes, function(index, element) {
					if (typeof s4Map.markers[element.node.nid] == 'undefined') {
						var hours = '';
						if (typeof element.node.students != 'undefined') {
							var hours = '<strong>' + element.node.hours + 
							'</strong> hours by <strong>' + 
							element.node.students + '</strong> student';
							if (element.node.students > 1) {
								hours += 's';
							}
						}
						s4Map.markers[element.node.nid] = 
							s4Map.addMarker(element.node.latitude, element.node.longitude,
							'<br/><strong><a href="' + element.node.path + '">' + element.node.title + 
							'</a></strong><div class="hours">' + hours + '</div>');
					}
				});
				$('#map-loading-indicator').hide();
			});
		},
		
		getCircleSize : function(size) {
			var meters = s4Map.getMetersPerPixels();
			if (size > s4Map.maxSize) {
				return s4Map.maxSize * meters;
			}
			if (size < s4Map.minSize) {
				return s4Map.minSize * meters;
			}
			return size * meters;
		},
		
		getMetersPerPixels : function() {
			if (typeof s4Map.zoomStorage[s4Map.map.getZoom()] == 'undefined') {
				var boundaries = s4Map.map.getBounds();
				var meters = google.maps.geometry.spherical.computeDistanceBetween(boundaries.getSouthWest(), boundaries.getNorthEast());
				var pixels = (this.element.width() ^ 2) + (this.element.height() ^ 2);
				s4Map.zoomStorage[s4Map.map.getZoom()] = (meters / pixels);
			}
			return s4Map.zoomStorage[s4Map.map.getZoom()];
		},
		
		addMarker : function(lat, lon, message, icon, shadow) {
			var latLng = new google.maps.LatLng(lat, lon);
			var markerOptions = {
				position: latLng, 
				map: s4Map.map
			};
			if (icon) {
				markerOptions.icon = icon;
			}
			if (shadow) {
				markerOptions.shadow = shadow;
			}
			var marker = new google.maps.Marker(markerOptions);
			if (message) {
				google.maps.event.addListener(marker, 'click', function(e) {
				  	if (s4Map.activeInfoWindow && typeof s4Map.activeInfoWindow.close != 'undefined') {
				  		s4Map.activeInfoWindow.close();
				  	}
				  	var infoWindow = new google.maps.InfoWindow({
					    content: '<div class="infowindow-message">' + message + '</div>',
					    maxWidth: 400
					});
					infoWindow.open(s4Map.map,marker);
					s4Map.activeInfoWindow = infoWindow;
				});
			}
			return marker;
		},
		
		addCircle : function(lat, lon, radius, message) {
			var latLng = new google.maps.LatLng(lat, lon);
			var marker = new google.maps.Circle({
				center: latLng,
				fillColor: '#4b8bba',
				fillOpacity: 0.7,
				radius: s4Map.getCircleSize(radius),
				strokeColor: '#4b8bba',
				strokeWeight: 1,
				clickable: true, 
				map: s4Map.map
			});
			marker.set('defaultRadius', radius);
			if (typeof message !== 'undefined') {
				google.maps.event.addListener(marker, 'click', function(e) {
				  	if (s4Map.activeInfoWindow && typeof s4Map.activeInfoWindow.close != 'undefined') {
				  		s4Map.activeInfoWindow.close();
				  	}
				  	var infoWindow = new google.maps.InfoWindow({
					    content: message
					});
					infoWindow.open(s4Map.map,marker);
					s4Map.activeInfoWindow = infoWindow;

				});
			}
			return marker;
		},
		
		resizeCircles : function() {
			var mapZoom = s4Map.map.getZoom();
			$.each(s4Map.markers, function(index, circle) {
			});
		}
	};

	Drupal.s4Map = s4Map;

})(jQuery);