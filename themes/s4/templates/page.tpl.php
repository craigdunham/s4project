<div id="branding">
	<div class="container">
		<div class="row">
			<div class="span4">
				<?php if ($site_name): ?>
					<h1>
						<?php if ($logo): ?>
						<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
							<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
						</a>
						<?php endif; ?>
						<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
							<?php print $site_name; ?>
						</a>
						<?php if($original_title = variable_get('s4_original_site_title', FALSE)): ?>
		  			 <div class="original-title">
		  			   <?php print t('Part of !link', array('!link' => l($original_title, '<front>'))); ?>
		  			 </div>
					<?php endif; ?>
					</h1>
					
				<?php endif; ?>
			</div>
			
			<div class="span6 offset2">
				<?php if($page['search']): ?>
					<div id="search">
						<?php print render($page['search']); ?>
					</div>
				<?php endif; ?>
			</div>
		</div>
	</div>
</div>
<div id="navigation">
	<div class="container">
		<?php print theme('links__system_main_menu', array(
          'links' => $main_menu,
          'attributes' => array(
            'id' => 'main-menu',
            'class' => array('links', 'nav nav-tabs'),
          ),
        )); ?>
	</div>
</div>
<div class="container">
<?php if($page['content_top_wide']): ?>
	<div id="user-progress">
		<?php print render($page['content_top_wide']); ?>
	</div>
<?php endif; ?>
<div id="page">
	
	
	<div class="page-header">
		<?php if ($breadcrumb) print $breadcrumb; ?>
		<?php if ($messages): ?>
		    <div id="messages">
			      <?php print $messages; ?>
		    </div>
		<?php endif; ?>
		<?php if($page['content_subscriptions']): ?>
			<div id="subscriptions">
				<?php print render($page['content_subscriptions']); ?>
			</div>
		<?php endif; ?>
		

		<?php if(!$is_front && $title): ?>
			<h1 class="title" id="page-title"><?php print $title; ?></h1>
		<?php endif; ?>
		<?php if ($tabs = render($tabs)): ?>
       		<div class="tabs"><?php print $tabs; ?></div>
      	<?php endif; ?>
      	<?php if ($page['help']): ?>
			<div id="help">
			  <?php print render($page['help']); ?>
			</div>
      	<?php endif; ?>
      <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
	</div>
		<?php if($page['content_top_left'] || $page['content_top_right']): ?>
			<div id="content_top" class="row">
				<?php if($page['content_top_left']): ?>
					<div <?php if($page['content_top_right']): ?>class="span6"<?php else: ?>class="span12"<?php endif; ?>>
						<?php print render($page['content_top_left']); ?>
					</div>
				<?php endif; ?>
				<?php if($page['content_top_right']): ?>
					<div class="span6">
						<?php print render($page['content_top_right']); ?>
					</div>
				<?php endif; ?>
			</div>
		<?php endif; ?>
		<div id="content_middle" class="row">
			<?php if($page['content']): ?>
				<div id="content" <?php if($page['content_right']): ?>class="span8"<?php else: ?>class="span12"<?php endif; ?>>
					<?php print render($page['content']); ?>
				</div>
			<?php endif; ?>
			<?php if($page['content_right']): ?>
				<div class="span4 column">
					<?php print render($page['content_right']); ?>
				</div>
			<?php endif; ?>
		</div>
		<?php if($page['content_bottom']): ?>
			<div class="clear"></div>
			<?php print render($page['content_bottom']); ?>
		<?php endif; ?>
	</div>
</div>
<?php if($page['footer_map']): ?>
<div id="footer-map">
	<div id="map-shadow-top" class="shadow"></div>
	<?php print render($page['footer_map']); ?>
	<div id="map-shadow-bottom" class="shadow"></div>
</div>
<?php endif; ?>

<?php if($page['footer_left'] || $page['footer_middle'] || $page['footer_right'] || $page['footer_bottom']): ?>
	<div id="footer">
		<div class="container">
			<?php if($page['footer_left']): ?>
				<div class="triptych">
					<?php print render($page['footer_left']); ?>
				</div>
			<?php endif; ?>
			<?php if($page['footer_middle']): ?>
				<div class="triptych margin">
					<?php print render($page['footer_middle']); ?>
				</div>
			<?php endif; ?>
			<?php if($page['footer_right']): ?>
				<div class="triptych margin">
					<?php print render($page['footer_right']); ?>
				</div>
			<?php endif; ?>
			<div class="clear"></div>
			<?php if($page['footer_bottom']): ?>
				<?php print render($page['footer_bottom']); ?>
			<?php endif; ?>
			<div class="clear">
			</div>
		</div>
	</div>
<?php endif; ?>