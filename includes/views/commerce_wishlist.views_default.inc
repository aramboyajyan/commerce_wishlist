<?php

/**
 * Views for the default Wishlist UI.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_wishlist_views_default_views() {
  $views = array();

  /**
   * View showing the wishlist products of a user.
   */
  $view_wishlist_user = new view();
  $view_wishlist_user->name = 'wishlist';
  $view_wishlist_user->description = 'Display a list of products added to wishlist.';
  $view_wishlist_user->tag = 'commerce';
  $view_wishlist_user->base_table = 'commerce_wishlist';
  $view_wishlist_user->human_name = 'Wishlist';
  $view_wishlist_user->core = 0;
  $view_wishlist_user->api_version = '3.0';
  $view_wishlist_user->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view_wishlist_user->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'My wishlist';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'commerce_wishlist';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'commerce_price' => 'commerce_price',
    'add_to_cart_form' => 'add_to_cart_form',
    'remove_wishlist' => 'add_to_cart_form',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'add_to_cart_form' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'remove_wishlist' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'No products have been added yet.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Relationship: Commerce Wishlist: Product display (node) */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'commerce_wishlist';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Commerce Wishlist: Product */
  $handler->display->display_options['relationships']['product_id']['id'] = 'product_id';
  $handler->display->display_options['relationships']['product_id']['table'] = 'commerce_wishlist';
  $handler->display->display_options['relationships']['product_id']['field'] = 'product_id';
  $handler->display->display_options['relationships']['product_id']['required'] = TRUE;
  /* Relationship: Commerce Wishlist: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_wishlist';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'product_id';
  $handler->display->display_options['fields']['commerce_price']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['relationship'] = 'product_id';
  /* Contextual filter: Commerce Wishlist: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'commerce_wishlist';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';

  /* Display: User wishlist page */
  $handler = $view_wishlist_user->new_display('page', 'User wishlist page', 'commerce_wishlist_user');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Wishlist: Product display (node) */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'commerce_wishlist';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Commerce Wishlist: Product */
  $handler->display->display_options['relationships']['product_id']['id'] = 'product_id';
  $handler->display->display_options['relationships']['product_id']['table'] = 'commerce_wishlist';
  $handler->display->display_options['relationships']['product_id']['field'] = 'product_id';
  $handler->display->display_options['relationships']['product_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'product_id';
  $handler->display->display_options['fields']['commerce_price']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => 'calculated_sell_price',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'product_id';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = 'Actions';
  $handler->display->display_options['fields']['add_to_cart_form']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'product';
  /* Field: Commerce Wishlist: Remove */
  $handler->display->display_options['fields']['remove_wishlist']['id'] = 'remove_wishlist';
  $handler->display->display_options['fields']['remove_wishlist']['table'] = 'commerce_wishlist';
  $handler->display->display_options['fields']['remove_wishlist']['field'] = 'remove_wishlist';
  $handler->display->display_options['fields']['remove_wishlist']['label'] = 'Operations';
  $handler->display->display_options['fields']['remove_wishlist']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['remove_wishlist']['text'] = 'Remove from wishlist';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/wishlist';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Wishlist';
  $handler->display->display_options['menu']['weight'] = '14';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Products';
  $handler->display->display_options['tab_options']['description'] = 'Manage products and product types in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: User wishlist block */
  $handler = $view_wishlist_user->new_display('block', 'User wishlist block', 'commerce_wishlist_block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Wishlist: Product display (node) */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'commerce_wishlist';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Commerce Wishlist: Product */
  $handler->display->display_options['relationships']['product_id']['id'] = 'product_id';
  $handler->display->display_options['relationships']['product_id']['table'] = 'commerce_wishlist';
  $handler->display->display_options['relationships']['product_id']['field'] = 'product_id';
  $handler->display->display_options['relationships']['product_id']['required'] = TRUE;
  /* Relationship: Commerce Wishlist: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_wishlist';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => 'calculated_sell_price',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Wishlist';

  $views[$view_wishlist_user->name] = $view_wishlist_user;

  return $views;
}
