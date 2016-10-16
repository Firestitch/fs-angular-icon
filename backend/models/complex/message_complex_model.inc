<?
	class CMODEL_MESSAGE extends BCMODEL_MESSAGE {
		
		const TAG_USER_PASSWORD_RESET = "USER_PASSWORD_RESET";
/*
		public function queue_internal($conversation_cmodel,$from_object_cmodel,$to_object_cmodels) {

			$message_queue_cmodel = $this->get_internal_message()->create_message_queue();

			$message_queue_cmodel->save();

			if(!$conversation_cmodel)
				$conversation_cmodel = CMODEL_CONVERSATION::create()
												->set_create_object_id($from_object_cmodel->get_object_id())
												->save();

			$to_object_cmodels = is_array($to_object_cmodels) ? $to_object_cmodels : array($to_object_cmodels);

			$objects = array($from_object_cmodel) + $to_object_cmodels;

			$conversation_cmodel->add_objects($objects);

			$conversation_message_cmodel = CMODEL_CONVERSATION_MESSAGE::create()	
														->set_object_id($from_object_cmodel->get_object_id())
														->set_conversation_id($conversation_cmodel->get_conversation_id())
														->set_message_queue_id($message_queue_cmodel->get_message_queue_id())
														->save();




		}
		*/
	}