<div id="branding">
	<div class="container">
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
			</h1>
		<?php endif; ?>
		<?php if($page['search']): ?>
			<div id="search">
				<?php print render($page['search']); ?>
			</div>
		<?php endif; ?>
		<?php /*if($logged_in): ?>
			<div id="dashboard-link" class="tool-link">
				<span class="icon"></span>
				<a href="<?php print $base_path; ?>dashboard">Dashboard</a>
			</div>
		<?php endif;*/ ?>
		<?php if($page['tools_left'] || $page['tools_middle'] || $page['tools_right']): ?>

			<div id="tool-menu" class="tool-link">
				<span class="icon"></span>
				<a href="#tools">Staff Tools</a>
			</div>
		<?php endif; ?>
	</div>
	<div class="clear"></div>
<?php if($page['tools_left'] || $page['tools_middle'] || $page['tools_right']): ?>
	<div id="tools">
		<div class="container">
		<a name="tools"></a>
		<div class="triptych column-first">
			<?php print render($page['tools_left']); ?>
		</div>
		<div class="triptych">
			<?php print render($page['tools_middle']); ?>
		</div>
		<div class="triptych column-last">
			<?php print render($page['tools_right']); ?>
		</div>
		<div class="clear"></div>
		</div>
	</div>
<?php endif; ?>

</div>
<div id="navigation">
	<div class="container">
		<?php print $breadcrumb; ?>
		
		<?php print theme('links__system_main_menu', array(
          'links' => $main_menu,
          'attributes' => array(
            'id' => 'main-menu',
            'class' => array('links', 'clearfix'),
          ),
        )); ?>
	</div>
</div>
<?php if($page['content_top_wide']): ?>
	<div id="user-progress">
		<div class="container">
		<?php print render($page['content_top_wide']); ?>
		</div>
	</div>
<?php endif; ?>
<div id="page">
	
	<div class="container">
	
	
	<div class="page-header">
		<?php if($page['content_subscriptions']): ?>
			<div id="subscriptions">
				<?php print render($page['content_subscriptions']); ?>
			</div>
		<?php endif; ?>
		<?php if ($messages): ?>
		    <div id="messages">
		      <?php print $messages; ?>
		    </div>
		<?php endif; ?>

		<?php if(!$is_front && $title): ?>
			<h1 class="title" id="page-title"><?php print $title; ?></h1>
		<?php endif; ?>
		<?php if ($tabs = render($tabs)): ?>
       		<div class="tabs"><?php print $tabs; ?></div>
      	<?php endif; ?>
	</div>
		<?php if($page['content_top_left'] || $page['content_top_right']): ?>
			<div id="content_top">
				<?php if($page['content_top_left']): ?>
					<div class="column-equal">
						<?php print render($page['content_top_left']); ?>
					</div>
				<?php endif; ?>
				<?php if($page['content_top_right']): ?>
					<div class="column-equal column-last">
						<?php print render($page['content_top_right']); ?>
					</div>
				<?php endif; ?>
			</div>
		<?php endif; ?>
		<div id="content_middle">
			<?php if($page['content']): ?>
				<div id="content">
					<?php print render($page['content']); ?>
				</div>
			<?php endif; ?>
			<?php if($page['content_right']): ?>
				<div class="column column-last">
					<?php print render($page['content_right']); ?>
				</div>
			<?php endif; ?>
		</div>
		<?php if($page['content_bottom']): ?>
			<div class="clear"></div>
			<?php print render($page['content_bottom']); ?>
		<?php endif; ?>
	</div>
	<div class="clear"></div>
</div>

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
		<a href="http://s4.csumb.edu">Powered by the S4 Project</a>
		<div class="clear">
		</div>
	</div>
</div>