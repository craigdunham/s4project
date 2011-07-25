(function($) {
	$(document).ready(function() {
		if($('#site-map').length) {
			s4Map.init('site-map');
		}
		if($('#site-list-map').length) {
			$(document).scroll(function() {
				var columnTop = $('#content_middle .column').position();
				if($(document).scrollTop() > columnTop.top) {
					$('#site-list-map').css('position', 'fixed').css('top', 0);
				}
				else {
					$('#site-list-map').css('position', 'relative');
				}
			});
			s4Map.init('site-list-map');
			$('.map-link').hide();
			
			var bounds = new google.maps.LatLngBounds();
			$('.map-link').each(function(index, element) {
				if($(this).attr('lat') == 0 && !$(this).attr('lon') == 0 ) {
					$(this).html('&times;').addClass('disabled').show();
					return null;
				}
				var letter = String.fromCharCode("A".charCodeAt(0) + index);
				s4Map.addMarker($(this).attr('lat'), 
								$(this).attr('lon'), 
								false, 
								"http://www.google.com/mapfiles/marker" + letter + ".png");
			  	bounds.extend(new google.maps.LatLng($(this).attr('lat'), $(this).attr('lon')));
			  	$(this).html(letter).show();
			  	$(this).click(function() {
		  		   	s4Map.setCenter($(this).attr('lat'), $(this).attr('lon'));
		  		   	return false;
		  		});
			});
			s4Map.map.fitBounds(bounds);
			
		}
	});

var s4Map = {
	
	map : null,
	
	activeInfoWindow : null,
	
	markers : [ ],
	
	style : [ ],
	
	init : function(mapID) {
		var center = new google.maps.LatLng(Drupal.settings.s4_map.lat, Drupal.settings.s4_map.lon);
		s4Map.map = new google.maps.Map(document.getElementById(mapID),
        				   {'center' : center,
							'zoom' : Drupal.settings.s4_map.zoom,
							'mapTypeControlOptions' : {
						       'mapTypeIds': [google.maps.MapTypeId.ROADMAP, 's4']
						    	} 
						    });
		
		var mapStyleType = new google.maps.StyledMapType(
					      s4Map.style, { name : 'Service'} );
		s4Map.map.mapTypes.set('s4', mapStyleType);
		s4Map.map.setMapTypeId('s4');
		if($('#' + mapID).hasClass('autofill')) {
			google.maps.event.addListener(s4Map.map, 'bounds_changed', s4Map.reloadMap);
	
//			google.maps.event.trigger(s4Map.map, 'dragend');
		}
	},
	
	setCenter : function(lat, lon) {
		var newCenter = new google.maps.LatLng(lat, lon);
		s4Map.map.setCenter(newCenter);
		s4Map.map.setZoom(15);
	},
	
	reloadMap : function() {
		var boundaries = s4Map.map.getBounds();
		$.getJSON(Drupal.settings.basePath + 'json/map/sites?lat_min=' + boundaries.getSouthWest().Ka +'&lat_max=' + boundaries.getNorthEast().Ka + '&lon_min=' + boundaries.getSouthWest().La + '&lon_max=' + boundaries.getNorthEast().La ,function(data) {
			$.each(data.nodes, function(index, element) {
				if(s4Map.markers[element.node.nid] === undefined) {
					s4Map.markers[element.node.nid] = 
						s4Map.addMarker(element.node.latitude, element.node.longitude, '<a href="' + element.node.path + '">' + element.node.title + '</a>');
				}
			});
		});
	},
	
	addMarker : function(lat, lon, message, icon, shadow) {
		var latLng = new google.maps.LatLng(lat, lon);
		var markerOptions = {
			position: latLng, 
			map: s4Map.map,
		};
		if(icon) {
			markerOptions.icon = icon;
		}
		if(shadow) {
			markerOptions.shadow = shadow;
		}
		var marker = new google.maps.Marker(markerOptions);
		if(message) {
			var speakie = new google.maps.InfoWindow({
			    content: message
			});
	
			google.maps.event.addListener(marker, 'click', function(e) {
			  	if(s4Map.activeInfoWindow) {
			  		s4Map.activeInfoWindow.close();
			  	}
			  	speakie.open(s4Map.map,marker);
			  	s4Map.activeInfoWindow = speakie;
			});
		}
		return marker;
	},
	
	addCircle : function(lat, lon) {
		var latLng = new google.maps.LatLng(lat, lon);
		var marker = new google.maps.Circle({
			center: latLng,
			fillColor: '#4b8bba',
			fillOpacity: 0.7,
			radius: 20,
			strokeColor: '#4b8bba',
			strokeWeight: 1, 
			map: s4Map.map,
		});
		return marker;
	},
	
	resizeCircles : function() {
		var mapZoom = s4Map.map.getZoom();
		$.each(s4Map.markers, function(index, circle) {
		});
	}
}


})(jQuery);