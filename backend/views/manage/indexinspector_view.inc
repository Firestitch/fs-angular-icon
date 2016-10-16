<?
	class VIEW_MANAGE_INDEXINSPECTOR extends VIEW {
	
		function __construct() {
			parent::__construct("manage","indexinspector",[],"index-form");
			$this->set_view("indexes",APPLICATION::get_view("manage","indexinspectlist"));
		}
		
		function init() {
			$this->load();
		}
		function load() { $this->get_view("indexes")->load(); }
	}