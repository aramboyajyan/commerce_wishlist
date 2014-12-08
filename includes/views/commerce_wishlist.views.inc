<?php

/**
 * Export Drupal Commerce products to Views.
 */

/**
 * Implements hook_views_data()
 */
function commerce_wishlist_views_data() {
  $data = array();

  $data['commerce_wishlist']['table']['group'] = t('Commerce Wishlist');

  $data['commerce_wishlist']['table']['base'] = array(
    'field' => 'wishlist_id',
    'title' => t('Commerce Wishlist'),
    'help' => t('Table used for storing wishlist products.'),
    'entity type' => 'commerce_product',
    'access query tag' => 'commerce_product_access',
    'defaults' => array(
      'field' => 'product_id',
    ),
  );

  // Expose the commerce product ID.
  $data['commerce_wishlist']['product_id'] = array(
    'title' => t('Product ID'),
    'help' => t('The unique internal identifier of the product.'),
    'field' => array(
      'handler' => 'commerce_product_handler_field_product',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Product'),
      'help' => t("Relate this wishlist to its owner's user account"),
      'handler' => 'views_handler_relationship',
      'base' => 'commerce_product',
      'base field' => 'product_id',
      'field' => 'product_id',
      'label' => t('Wishlist product display'),
    ),
  );

  // Expose the product node ID.
  $data['commerce_wishlist']['nid'] = array(
    'title' => t('Node ID'),
    'help' => t('Unique identifier for the node which references the wishlist product.'),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Product display (node)'),
      'help' => t("Relate this wishlist to its owner's user account"),
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'field' => 'nid',
      'label' => t('Wishlist product display'),
    ),
  );

  // Expose the creator uid.
  $data['commerce_wishlist']['uid'] = array(
    'title' => t('Uid'),
    'help' => t("The owner's user ID."),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name', // display this field in the summary
    ),
    'filter' => array(
      'title' => t('Owner'),
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Owner'),
      'help' => t("Relate this wishlist to its owner's user account"),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'field' => 'uid',
      'label' => t('Wishlist owner'),
    ),
  );

  // Expose the timestamp for when the product has been added to wishlist.
  $data['commerce_wishlist']['added'] = array(
    'title' => t('Added on'),
    'help' => t('Timestamp for when the product has been added to wishlist.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Expose links to operate on the product.
  $data['commerce_wishlist']['remove_wishlist'] = array(
    'field' => array(
      'title' => t('Remove'),
      'help' => t('Provide a simple link to remove a product from the wishlist.'),
      'handler' => 'commerce_wishlist_handler_field_product_link_remove',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function commerce_wishlist_views_plugins() {
  $plugins = array();
  $plugins['access'] = array(
    'commerce_wishlist' => array(
      'title'   => t('Wishlist access check'),
      'help'    => t('Use this only for checking whether or not a user can access a wishlist.'),
      'handler' => 'commerce_wishlist_views_access_plugin',
      'path'    => drupal_get_path('module', 'commerce_wishlist') . '/includes/views',
    ),
  );

  return $plugins;
}

/**
 * Custom class for declaring a custom views access plugin.
 */
class commerce_wishlist_views_access_plugin extends views_plugin_access {
  function summary_title() {
    return t('This is summary title');
  }
  function access($account) {
    return commerce_wishlist_user_wishlist_access($account, $this);
  }
  function get_access_callback() {
    return array('commerce_wishlist_user_wishlist_access', array(1, $this));
  }
}
