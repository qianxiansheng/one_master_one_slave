--define_symbol att_dispatch_client_can_send_now=0x02004461
--define_symbol att_dispatch_client_request_can_send_now_event=0x02004467
--define_symbol att_dispatch_register_client=0x0200446d
--define_symbol att_dispatch_register_server=0x02004481
--define_symbol att_dispatch_server_can_send_now=0x02004495
--define_symbol att_dispatch_server_request_can_send_now_event=0x0200449b
--define_symbol att_emit_general_event=0x0200454d
--define_symbol att_server_can_send_packet_now=0x02004c85
--define_symbol att_server_deferred_read_response=0x02004c89
--define_symbol att_server_get_mtu=0x02004ca1
--define_symbol att_server_indicate=0x02004d19
--define_symbol att_server_init=0x02004d9d
--define_symbol att_server_notify=0x02004dd9
--define_symbol att_server_register_packet_handler=0x02004ef1
--define_symbol att_server_request_can_send_now_event=0x02004efd
--define_symbol att_set_db=0x02004f19
--define_symbol att_set_read_callback=0x02004f2d
--define_symbol att_set_write_callback=0x02004f39
--define_symbol bd_addr_cmp=0x0200510d
--define_symbol bd_addr_copy=0x02005113
--define_symbol bd_addr_to_str=0x0200511d
--define_symbol big_endian_read_16=0x02005155
--define_symbol big_endian_read_32=0x0200515d
--define_symbol big_endian_store_16=0x02005171
--define_symbol big_endian_store_32=0x0200517d
--define_symbol btstack_config=0x020052dd
--define_symbol btstack_memory_pool_create=0x0200541b
--define_symbol btstack_memory_pool_free=0x02005445
--define_symbol btstack_memory_pool_get=0x020054a5
--define_symbol btstack_push_user_msg=0x0200550d
--define_symbol btstack_push_user_runnable=0x02005519
--define_symbol btstack_reset=0x02005525
--define_symbol char_for_nibble=0x02005817
--define_symbol eTaskConfirmSleepModeStatus=0x02005bc9
--define_symbol gap_add_dev_to_periodic_list=0x02006239
--define_symbol gap_add_whitelist=0x02006249
--define_symbol gap_aes_encrypt=0x02006255
--define_symbol gap_clear_white_lists=0x0200628d
--define_symbol gap_clr_adv_set=0x02006299
--define_symbol gap_clr_periodic_adv_list=0x020062a5
--define_symbol gap_create_connection_cancel=0x020062b1
--define_symbol gap_default_periodic_adv_sync_transfer_param=0x020062bd
--define_symbol gap_disconnect=0x020062d5
--define_symbol gap_disconnect_all=0x02006301
--define_symbol gap_ext_create_connection=0x02006341
--define_symbol gap_get_connection_parameter_range=0x02006419
--define_symbol gap_le_read_channel_map=0x02006455
--define_symbol gap_periodic_adv_create_sync=0x020064c1
--define_symbol gap_periodic_adv_create_sync_cancel=0x020064e5
--define_symbol gap_periodic_adv_set_info_transfer=0x020064f1
--define_symbol gap_periodic_adv_sync_transfer=0x02006501
--define_symbol gap_periodic_adv_sync_transfer_param=0x02006511
--define_symbol gap_periodic_adv_term_sync=0x0200652d
--define_symbol gap_read_antenna_info=0x020065b5
--define_symbol gap_read_periodic_adv_list_size=0x020065c1
--define_symbol gap_read_phy=0x020065cd
--define_symbol gap_read_remote_used_features=0x020065d9
--define_symbol gap_read_remote_version=0x020065e5
--define_symbol gap_read_rssi=0x020065f1
--define_symbol gap_remove_whitelist=0x020065fd
--define_symbol gap_rmv_adv_set=0x02006679
--define_symbol gap_rmv_dev_from_periodic_list=0x02006685
--define_symbol gap_rx_test_v2=0x02006695
--define_symbol gap_rx_test_v3=0x020066a5
--define_symbol gap_set_adv_set_random_addr=0x020066f1
--define_symbol gap_set_callback_for_next_hci=0x0200672d
--define_symbol gap_set_connection_cte_request_enable=0x0200674d
--define_symbol gap_set_connection_cte_response_enable=0x02006769
--define_symbol gap_set_connection_cte_rx_param=0x02006779
--define_symbol gap_set_connection_cte_tx_param=0x020067cd
--define_symbol gap_set_connection_parameter_range=0x02006819
--define_symbol gap_set_connectionless_cte_tx_enable=0x02006831
--define_symbol gap_set_connectionless_cte_tx_param=0x02006841
--define_symbol gap_set_connectionless_iq_sampling_enable=0x0200689d
--define_symbol gap_set_data_length=0x020068f9
--define_symbol gap_set_def_phy=0x02006911
--define_symbol gap_set_ext_adv_data=0x02006921
--define_symbol gap_set_ext_adv_enable=0x02006939
--define_symbol gap_set_ext_adv_para=0x020069a9
--define_symbol gap_set_ext_scan_enable=0x02006a79
--define_symbol gap_set_ext_scan_para=0x02006a91
--define_symbol gap_set_ext_scan_response_data=0x02006b31
--define_symbol gap_set_host_channel_classification=0x02006b49
--define_symbol gap_set_periodic_adv_data=0x02006b59
--define_symbol gap_set_periodic_adv_enable=0x02006bc9
--define_symbol gap_set_periodic_adv_para=0x02006bd9
--define_symbol gap_set_periodic_adv_rx_enable=0x02006bf1
--define_symbol gap_set_phy=0x02006c01
--define_symbol gap_set_random_device_address=0x02006c1d
--define_symbol gap_start_ccm=0x02006c4d
--define_symbol gap_test_end=0x02006c95
--define_symbol gap_tx_test_v2=0x02006ca1
--define_symbol gap_tx_test_v4=0x02006cb9
--define_symbol gap_update_connection_parameters=0x02006cdd
--define_symbol gap_vendor_tx_continuous_wave=0x02006d21
--define_symbol gatt_client_cancel_write=0x02007249
--define_symbol gatt_client_discover_characteristic_descriptors=0x0200726f
--define_symbol gatt_client_discover_characteristics_for_handle_range_by_uuid128=0x020072af
--define_symbol gatt_client_discover_characteristics_for_handle_range_by_uuid16=0x020072ff
--define_symbol gatt_client_discover_characteristics_for_service=0x0200734f
--define_symbol gatt_client_discover_primary_services=0x02007385
--define_symbol gatt_client_discover_primary_services_by_uuid128=0x020073b7
--define_symbol gatt_client_discover_primary_services_by_uuid16=0x020073fb
--define_symbol gatt_client_execute_write=0x02007439
--define_symbol gatt_client_find_included_services_for_service=0x0200745f
--define_symbol gatt_client_get_mtu=0x0200748d
--define_symbol gatt_client_is_ready=0x02007551
--define_symbol gatt_client_listen_for_characteristic_value_updates=0x02007567
--define_symbol gatt_client_prepare_write=0x02007589
--define_symbol gatt_client_read_characteristic_descriptor_using_descriptor_handle=0x020075c5
--define_symbol gatt_client_read_long_characteristic_descriptor_using_descriptor_handle=0x020075ef
--define_symbol gatt_client_read_long_characteristic_descriptor_using_descriptor_handle_with_offset=0x020075f5
--define_symbol gatt_client_read_long_value_of_characteristic_using_value_handle=0x02007623
--define_symbol gatt_client_read_long_value_of_characteristic_using_value_handle_with_offset=0x02007629
--define_symbol gatt_client_read_multiple_characteristic_values=0x02007657
--define_symbol gatt_client_read_value_of_characteristic_using_value_handle=0x02007687
--define_symbol gatt_client_read_value_of_characteristics_by_uuid128=0x020076b5
--define_symbol gatt_client_read_value_of_characteristics_by_uuid16=0x02007701
--define_symbol gatt_client_register_handler=0x0200774d
--define_symbol gatt_client_reliable_write_long_value_of_characteristic=0x02007759
--define_symbol gatt_client_signed_write_without_response=0x02007b8d
--define_symbol gatt_client_write_characteristic_descriptor_using_descriptor_handle=0x02007c51
--define_symbol gatt_client_write_client_characteristic_configuration=0x02007c8b
--define_symbol gatt_client_write_long_characteristic_descriptor_using_descriptor_handle=0x02007cdd
--define_symbol gatt_client_write_long_characteristic_descriptor_using_descriptor_handle_with_offset=0x02007ced
--define_symbol gatt_client_write_long_value_of_characteristic=0x02007d29
--define_symbol gatt_client_write_long_value_of_characteristic_with_offset=0x02007d39
--define_symbol gatt_client_write_value_of_characteristic=0x02007d75
--define_symbol gatt_client_write_value_of_characteristic_without_response=0x02007dab
--define_symbol hci_add_event_handler=0x020093a1
--define_symbol hci_power_control=0x02009b49
--define_symbol hci_register_acl_packet_handler=0x02009cfd
--define_symbol kv_commit=0x0200a431
--define_symbol kv_get=0x0200a48d
--define_symbol kv_init=0x0200a499
--define_symbol kv_init_backend=0x0200a519
--define_symbol kv_put=0x0200a52d
--define_symbol kv_remove=0x0200a539
--define_symbol kv_remove_all=0x0200a56d
--define_symbol kv_value_modified=0x0200a59d
--define_symbol kv_value_modified_of_key=0x0200a5b9
--define_symbol kv_visit=0x0200a5c5
--define_symbol l2cap_add_event_handler=0x0200a655
--define_symbol l2cap_can_send_packet_now=0x0200a665
--define_symbol l2cap_create_le_credit_based_connection_request=0x0200a829
--define_symbol l2cap_credit_based_send=0x0200a971
--define_symbol l2cap_credit_based_send_continue=0x0200a99d
--define_symbol l2cap_disconnect=0x0200aa19
--define_symbol l2cap_get_le_credit_based_connection_credits=0x0200ac05
--define_symbol l2cap_get_peer_mtu_for_local_cid=0x0200ac21
--define_symbol l2cap_init=0x0200b061
--define_symbol l2cap_le_send_flow_control_credit=0x0200b157
--define_symbol l2cap_max_le_mtu=0x0200b465
--define_symbol l2cap_register_packet_handler=0x0200b58d
--define_symbol l2cap_register_service=0x0200b599
--define_symbol l2cap_request_can_send_now_event=0x0200b6a9
--define_symbol l2cap_request_connection_parameter_update=0x0200b6c3
--define_symbol l2cap_send_echo_request=0x0200bba5
--define_symbol l2cap_unregister_service=0x0200bc85
--define_symbol le_device_db_add=0x0200bcdd
--define_symbol le_device_db_find=0x0200bdb5
--define_symbol le_device_db_from_key=0x0200bde1
--define_symbol le_device_db_iter_cur=0x0200bde9
--define_symbol le_device_db_iter_cur_key=0x0200bded
--define_symbol le_device_db_iter_init=0x0200bdf1
--define_symbol le_device_db_iter_next=0x0200bdf9
--define_symbol le_device_db_remove_key=0x0200be1f
--define_symbol ll_adjust_conn_peer_tx_power=0x0200be4d
--define_symbol ll_aes_encrypt=0x0200be79
--define_symbol ll_config=0x0200beed
--define_symbol ll_free=0x0200bf23
--define_symbol ll_get_heap_free_size=0x0200bf2d
--define_symbol ll_hint_on_ce_len=0x0200bf41
--define_symbol ll_legacy_adv_set_interval=0x0200bf79
--define_symbol ll_malloc=0x0200bf89
--define_symbol ll_register_hci_acl_previewer=0x0200c0a1
--define_symbol ll_scan_set_fixed_channel=0x0200c105
--define_symbol ll_set_adv_access_address=0x0200c31d
--define_symbol ll_set_adv_coded_scheme=0x0200c329
--define_symbol ll_set_conn_acl_report_latency=0x0200c361
--define_symbol ll_set_conn_coded_scheme=0x0200c391
--define_symbol ll_set_conn_latency=0x0200c3bd
--define_symbol ll_set_conn_tx_power=0x0200c3ed
--define_symbol ll_set_def_antenna=0x0200c429
--define_symbol ll_set_initiating_coded_scheme=0x0200c449
--define_symbol ll_set_max_conn_number=0x0200c455
--define_symbol ll_set_tx_power_range=0x0200c4e9
--define_symbol nibble_for_char=0x0201ef69
--define_symbol platform_32k_rc_auto_tune=0x0201f015
--define_symbol platform_32k_rc_tune=0x0201f061
--define_symbol platform_calibrate_32k=0x0201f07d
--define_symbol platform_config=0x0201f081
--define_symbol platform_delete_timer=0x0201f1a9
--define_symbol platform_enable_irq=0x0201f1b1
--define_symbol platform_get_current_task=0x0201f1e5
--define_symbol platform_get_gen_os_driver=0x0201f209
--define_symbol platform_get_heap_status=0x0201f211
--define_symbol platform_get_link_layer_interf=0x0201f229
--define_symbol platform_get_task_handle=0x0201f231
--define_symbol platform_get_timer_counter=0x0201f251
--define_symbol platform_get_us_time=0x0201f255
--define_symbol platform_get_version=0x0201f259
--define_symbol platform_hrng=0x0201f261
--define_symbol platform_install_isr_stack=0x0201f269
--define_symbol platform_install_task_stack=0x0201f275
--define_symbol platform_patch_rf_init_data=0x0201f2ad
--define_symbol platform_printf=0x0201f2b9
--define_symbol platform_raise_assertion=0x0201f2cd
--define_symbol platform_rand=0x0201f2e1
--define_symbol platform_read_info=0x0201f2e5
--define_symbol platform_read_persistent_reg=0x0201f315
--define_symbol platform_reset=0x0201f321
--define_symbol platform_set_abs_timer=0x0201f335
--define_symbol platform_set_evt_callback=0x0201f339
--define_symbol platform_set_evt_callback_table=0x0201f34d
--define_symbol platform_set_irq_callback=0x0201f359
--define_symbol platform_set_irq_callback_table=0x0201f375
--define_symbol platform_set_rf_clk_source=0x0201f381
--define_symbol platform_set_rf_init_data=0x0201f38d
--define_symbol platform_set_rf_power_mapping=0x0201f399
--define_symbol platform_set_timer=0x0201f3a5
--define_symbol platform_shutdown=0x0201f3a9
--define_symbol platform_switch_app=0x0201f3ad
--define_symbol platform_trace_raw=0x0201f3c5
--define_symbol platform_write_persistent_reg=0x0201f3dd
--define_symbol printf_hexdump=0x0201f595
--define_symbol pvPortMalloc=0x0202006d
--define_symbol pvTaskIncrementMutexHeldCount=0x02020155
--define_symbol pvTimerGetTimerID=0x0202016d
--define_symbol pxPortInitialiseStack=0x02020199
--define_symbol reverse_128=0x02020381
--define_symbol reverse_24=0x02020387
--define_symbol reverse_256=0x0202038d
--define_symbol reverse_48=0x02020393
--define_symbol reverse_56=0x02020399
--define_symbol reverse_64=0x0202039f
--define_symbol reverse_bd_addr=0x020203a5
--define_symbol reverse_bytes=0x020203ab
--define_symbol sm_add_event_handler=0x02020709
--define_symbol sm_address_resolution_lookup=0x02020861
--define_symbol sm_authenticated=0x02020bdd
--define_symbol sm_authorization_decline=0x02020beb
--define_symbol sm_authorization_grant=0x02020c0b
--define_symbol sm_authorization_state=0x02020c2b
--define_symbol sm_bonding_decline=0x02020c45
--define_symbol sm_config=0x02021099
--define_symbol sm_config_conn=0x020210b1
--define_symbol sm_encryption_key_size=0x02021267
--define_symbol sm_just_works_confirm=0x020217ed
--define_symbol sm_le_device_key=0x02021b39
--define_symbol sm_passkey_input=0x02021bcf
--define_symbol sm_private_random_address_generation_get=0x02021f89
--define_symbol sm_private_random_address_generation_get_mode=0x02021f91
--define_symbol sm_private_random_address_generation_set_mode=0x02021f9d
--define_symbol sm_private_random_address_generation_set_update_period=0x02021fc5
--define_symbol sm_register_external_ltk_callback=0x02022101
--define_symbol sm_register_oob_data_callback=0x0202210d
--define_symbol sm_request_pairing=0x02022119
--define_symbol sm_send_security_request=0x02022bef
--define_symbol sm_set_accepted_stk_generation_methods=0x02022c15
--define_symbol sm_set_authentication_requirements=0x02022c21
--define_symbol sm_set_encryption_key_size_range=0x02022c2d
--define_symbol sscanf_bd_addr=0x02022f8d
--define_symbol sysSetPublicDeviceAddr=0x02023439
--define_symbol uuid128_to_str=0x02023c6d
--define_symbol uuid_add_bluetooth_prefix=0x02023cc5
--define_symbol uuid_has_bluetooth_prefix=0x02023ce5
--define_symbol uxListRemove=0x02023d01
--define_symbol uxQueueMessagesWaiting=0x02023d29
--define_symbol uxQueueMessagesWaitingFromISR=0x02023d51
--define_symbol uxQueueSpacesAvailable=0x02023d6d
--define_symbol uxTaskGetStackHighWaterMark=0x02023d99
--define_symbol uxTaskPriorityGet=0x02023db9
--define_symbol uxTaskPriorityGetFromISR=0x02023dd5
--define_symbol vListInitialise=0x02023e93
--define_symbol vListInitialiseItem=0x02023ea9
--define_symbol vListInsert=0x02023eaf
--define_symbol vListInsertEnd=0x02023edf
--define_symbol vPortEndScheduler=0x02023ef9
--define_symbol vPortEnterCritical=0x02023f25
--define_symbol vPortExitCritical=0x02023f69
--define_symbol vPortFree=0x02023f9d
--define_symbol vPortSuppressTicksAndSleep=0x02024041
--define_symbol vPortValidateInterruptPriority=0x02024169
--define_symbol vQueueDelete=0x020241c5
--define_symbol vQueueWaitForMessageRestricted=0x020241f1
--define_symbol vTaskDelay=0x02024235
--define_symbol vTaskInternalSetTimeOutState=0x02024281
--define_symbol vTaskMissedYield=0x02024291
--define_symbol vTaskPlaceOnEventList=0x0202429d
--define_symbol vTaskPlaceOnEventListRestricted=0x020242d5
--define_symbol vTaskPriorityDisinheritAfterTimeout=0x02024315
--define_symbol vTaskPrioritySet=0x020243c1
--define_symbol vTaskResume=0x02024489
--define_symbol vTaskStartScheduler=0x0202450d
--define_symbol vTaskStepTick=0x0202459d
--define_symbol vTaskSuspend=0x020245cd
--define_symbol vTaskSuspendAll=0x02024689
--define_symbol vTaskSwitchContext=0x02024699
--define_symbol xPortStartScheduler=0x02024741
--define_symbol xQueueAddToSet=0x02024845
--define_symbol xQueueCreateCountingSemaphore=0x02024869
--define_symbol xQueueCreateCountingSemaphoreStatic=0x020248a5
--define_symbol xQueueCreateMutex=0x020248e9
--define_symbol xQueueCreateMutexStatic=0x020248ff
--define_symbol xQueueCreateSet=0x02024919
--define_symbol xQueueGenericCreate=0x02024921
--define_symbol xQueueGenericCreateStatic=0x0202496d
--define_symbol xQueueGenericReset=0x020249d5
--define_symbol xQueueGenericSend=0x02024a61
--define_symbol xQueueGenericSendFromISR=0x02024bcd
--define_symbol xQueueGiveFromISR=0x02024c8d
--define_symbol xQueueGiveMutexRecursive=0x02024d31
--define_symbol xQueueIsQueueEmptyFromISR=0x02024d71
--define_symbol xQueueIsQueueFullFromISR=0x02024d95
--define_symbol xQueuePeek=0x02024dbd
--define_symbol xQueuePeekFromISR=0x02024ee5
--define_symbol xQueueReceive=0x02024f51
--define_symbol xQueueReceiveFromISR=0x0202507d
--define_symbol xQueueRemoveFromSet=0x02025111
--define_symbol xQueueSelectFromSet=0x02025133
--define_symbol xQueueSelectFromSetFromISR=0x02025145
--define_symbol xQueueSemaphoreTake=0x02025159
--define_symbol xQueueTakeMutexRecursive=0x020252c5
--define_symbol xTaskCheckForTimeOut=0x02025309
--define_symbol xTaskCreate=0x02025379
--define_symbol xTaskCreateStatic=0x020253d5
--define_symbol xTaskGetCurrentTaskHandle=0x02025445
--define_symbol xTaskGetSchedulerState=0x02025451
--define_symbol xTaskGetTickCount=0x0202546d
--define_symbol xTaskGetTickCountFromISR=0x02025479
--define_symbol xTaskIncrementTick=0x02025489
--define_symbol xTaskPriorityDisinherit=0x02025555
--define_symbol xTaskPriorityInherit=0x020255e9
--define_symbol xTaskRemoveFromEventList=0x0202567d
--define_symbol xTaskResumeAll=0x020256fd
--define_symbol xTaskResumeFromISR=0x020257c5
--define_symbol xTimerCreate=0x02025851
--define_symbol xTimerCreateStatic=0x02025885
--define_symbol xTimerCreateTimerTask=0x020258bd
--define_symbol xTimerGenericCommand=0x02025929
--define_symbol xTimerGetExpiryTime=0x02025999
--define_symbol xTimerGetTimerDaemonTaskHandle=0x020259b9