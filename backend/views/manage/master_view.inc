<?
	class VIEW_MANAGE_MASTER extends VIEW {

		protected $_version 		= null;
		protected $_upgrade_cmodel 	= null;

		function __construct() {

			$this->set_route("manage","master")->set_form("/manage/domaster/");

			if(!SYSTEM_MANAGER::is_system_mode_debug())
				$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);

			$this->_upgrade_cmodel = CMODEL_UPGRADE::create();

			try {

				$this->_version = value(array_keys($this->_upgrade_cmodel->get_queued_version_upgrade_items()),0);

			} catch(Exception $e) {
				APPLICATION::add_error($e->getMessage());
			}

			if(!$this->_version)
				$this->_version = $this->_upgrade_cmodel->get_current_version();

			$this->set_view("status",APPLICATION::get_base_view_instance("components","system_status"));
		}

		function init() {

			if($version=$this->request("version"))
				$this->_version = $version;

			$upgrade_versions = $this->_upgrade_cmodel->get_upgrade_versions();

			$this->set_var("versions",$upgrade_versions);
			$this->set_var("version",$this->_version);
		}

		function set_version($version) { $this->_version = $version; }
	}