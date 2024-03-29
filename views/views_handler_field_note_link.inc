<?php
// $Id: views_handler_field_node_link.inc,v 1.1 2008/09/03 19:21:29 merlinofchaos Exp $
/**
 * Field handler to present a link to the node.
 */
class views_handler_field_note_link extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['note_id'] = 'note_id';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $note_id = $values->{$this->aliases['note_id']};
    return l($text, "admin/devel_notes/note/$note_id");
  }
}
