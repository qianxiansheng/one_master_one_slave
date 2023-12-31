--define_symbol att_dispatch_client_can_send_now=0x00005875
--define_symbol att_dispatch_client_request_can_send_now_event=0x0000587b
--define_symbol att_dispatch_register_client=0x00005881
--define_symbol att_dispatch_register_server=0x00005895
--define_symbol att_dispatch_server_can_send_now=0x000058a9
--define_symbol att_dispatch_server_request_can_send_now_event=0x000058af
--define_symbol att_emit_general_event=0x00005961
--define_symbol att_server_can_send_packet_now=0x00006091
--define_symbol att_server_deferred_read_response=0x00006095
--define_symbol att_server_get_mtu=0x000060ad
--define_symbol att_server_indicate=0x00006125
--define_symbol att_server_init=0x000061a9
--define_symbol att_server_notify=0x000061e5
--define_symbol att_server_register_packet_handler=0x000062fd
--define_symbol att_server_request_can_send_now_event=0x00006309
--define_symbol att_set_db=0x00006325
--define_symbol att_set_read_callback=0x00006339
--define_symbol att_set_write_callback=0x00006345
--define_symbol bd_addr_cmp=0x000064b5
--define_symbol bd_addr_copy=0x000064bb
--define_symbol bd_addr_to_str=0x000064c5
--define_symbol big_endian_read_16=0x000064fd
--define_symbol big_endian_read_32=0x00006505
--define_symbol big_endian_store_16=0x00006519
--define_symbol big_endian_store_32=0x00006525
--define_symbol btstack_config=0x00006679
--define_symbol btstack_memory_pool_create=0x000067b7
--define_symbol btstack_memory_pool_free=0x000067e1
--define_symbol btstack_memory_pool_get=0x00006841
--define_symbol btstack_push_user_msg=0x000068a9
--define_symbol btstack_push_user_runnable=0x000068b5
--define_symbol btstack_reset=0x000068c1
--define_symbol char_for_nibble=0x00006b9d
--define_symbol eTaskConfirmSleepModeStatus=0x00006e81
--define_symbol gap_add_dev_to_periodic_list=0x000074ed
--define_symbol gap_add_whitelist=0x000074fd
--define_symbol gap_aes_encrypt=0x00007509
--define_symbol gap_clear_white_lists=0x00007541
--define_symbol gap_clr_adv_set=0x0000754d
--define_symbol gap_clr_periodic_adv_list=0x00007559
--define_symbol gap_create_connection_cancel=0x00007565
--define_symbol gap_default_periodic_adv_sync_transfer_param=0x00007571
--define_symbol gap_disconnect=0x00007589
--define_symbol gap_disconnect_all=0x000075b5
--define_symbol gap_ext_create_connection=0x000075f5
--define_symbol gap_get_connection_parameter_range=0x000076cd
--define_symbol gap_le_read_channel_map=0x00007709
--define_symbol gap_periodic_adv_create_sync=0x00007775
--define_symbol gap_periodic_adv_create_sync_cancel=0x00007799
--define_symbol gap_periodic_adv_set_info_transfer=0x000077a5
--define_symbol gap_periodic_adv_sync_transfer=0x000077b5
--define_symbol gap_periodic_adv_sync_transfer_param=0x000077c5
--define_symbol gap_periodic_adv_term_sync=0x000077e1
--define_symbol gap_read_antenna_info=0x00007869
--define_symbol gap_read_periodic_adv_list_size=0x00007875
--define_symbol gap_read_phy=0x00007881
--define_symbol gap_read_remote_used_features=0x0000788d
--define_symbol gap_read_remote_version=0x00007899
--define_symbol gap_read_rssi=0x000078a5
--define_symbol gap_remove_whitelist=0x000078b1
--define_symbol gap_rmv_adv_set=0x0000792d
--define_symbol gap_rmv_dev_from_periodic_list=0x00007939
--define_symbol gap_rx_test_v2=0x00007949
--define_symbol gap_rx_test_v3=0x00007959
--define_symbol gap_set_adv_set_random_addr=0x000079a5
--define_symbol gap_set_callback_for_next_hci=0x000079e1
--define_symbol gap_set_connection_cte_request_enable=0x00007a01
--define_symbol gap_set_connection_cte_response_enable=0x00007a1d
--define_symbol gap_set_connection_cte_rx_param=0x00007a2d
--define_symbol gap_set_connection_cte_tx_param=0x00007a81
--define_symbol gap_set_connection_parameter_range=0x00007acd
--define_symbol gap_set_connectionless_cte_tx_enable=0x00007ae5
--define_symbol gap_set_connectionless_cte_tx_param=0x00007af5
--define_symbol gap_set_connectionless_iq_sampling_enable=0x00007b51
--define_symbol gap_set_data_length=0x00007bad
--define_symbol gap_set_def_phy=0x00007bc5
--define_symbol gap_set_ext_adv_data=0x00007bd5
--define_symbol gap_set_ext_adv_enable=0x00007bed
--define_symbol gap_set_ext_adv_para=0x00007c5d
--define_symbol gap_set_ext_scan_enable=0x00007d35
--define_symbol gap_set_ext_scan_para=0x00007d4d
--define_symbol gap_set_ext_scan_response_data=0x00007ded
--define_symbol gap_set_host_channel_classification=0x00007e05
--define_symbol gap_set_periodic_adv_data=0x00007e15
--define_symbol gap_set_periodic_adv_enable=0x00007e85
--define_symbol gap_set_periodic_adv_para=0x00007e95
--define_symbol gap_set_periodic_adv_rx_enable=0x00007ead
--define_symbol gap_set_phy=0x00007ebd
--define_symbol gap_set_random_device_address=0x00007ed9
--define_symbol gap_start_ccm=0x00007f09
--define_symbol gap_test_end=0x00007f51
--define_symbol gap_tx_test_v2=0x00007f5d
--define_symbol gap_tx_test_v4=0x00007f75
--define_symbol gap_update_connection_parameters=0x00007f99
--define_symbol gap_vendor_tx_continuous_wave=0x00007fdd
--define_symbol gatt_client_cancel_write=0x00008505
--define_symbol gatt_client_discover_characteristic_descriptors=0x0000852b
--define_symbol gatt_client_discover_characteristics_for_handle_range_by_uuid128=0x0000856b
--define_symbol gatt_client_discover_characteristics_for_handle_range_by_uuid16=0x000085bb
--define_symbol gatt_client_discover_characteristics_for_service=0x0000860b
--define_symbol gatt_client_discover_primary_services=0x00008641
--define_symbol gatt_client_discover_primary_services_by_uuid128=0x00008673
--define_symbol gatt_client_discover_primary_services_by_uuid16=0x000086b7
--define_symbol gatt_client_execute_write=0x000086f3
--define_symbol gatt_client_find_included_services_for_service=0x00008719
--define_symbol gatt_client_get_mtu=0x00008747
--define_symbol gatt_client_is_ready=0x000087e9
--define_symbol gatt_client_listen_for_characteristic_value_updates=0x000087ff
--define_symbol gatt_client_prepare_write=0x00008821
--define_symbol gatt_client_read_characteristic_descriptor_using_descriptor_handle=0x0000885d
--define_symbol gatt_client_read_long_characteristic_descriptor_using_descriptor_handle=0x00008887
--define_symbol gatt_client_read_long_characteristic_descriptor_using_descriptor_handle_with_offset=0x0000888d
--define_symbol gatt_client_read_long_value_of_characteristic_using_value_handle=0x000088bb
--define_symbol gatt_client_read_long_value_of_characteristic_using_value_handle_with_offset=0x000088c1
--define_symbol gatt_client_read_multiple_characteristic_values=0x000088ef
--define_symbol gatt_client_read_value_of_characteristic_using_value_handle=0x0000891f
--define_symbol gatt_client_read_value_of_characteristics_by_uuid128=0x0000894d
--define_symbol gatt_client_read_value_of_characteristics_by_uuid16=0x00008999
--define_symbol gatt_client_register_handler=0x000089e5
--define_symbol gatt_client_reliable_write_long_value_of_characteristic=0x000089f1
--define_symbol gatt_client_signed_write_without_response=0x00008e21
--define_symbol gatt_client_write_characteristic_descriptor_using_descriptor_handle=0x00008ee5
--define_symbol gatt_client_write_client_characteristic_configuration=0x00008f1f
--define_symbol gatt_client_write_long_characteristic_descriptor_using_descriptor_handle=0x00008f71
--define_symbol gatt_client_write_long_characteristic_descriptor_using_descriptor_handle_with_offset=0x00008f81
--define_symbol gatt_client_write_long_value_of_characteristic=0x00008fbd
--define_symbol gatt_client_write_long_value_of_characteristic_with_offset=0x00008fcd
--define_symbol gatt_client_write_value_of_characteristic=0x00009009
--define_symbol gatt_client_write_value_of_characteristic_without_response=0x0000903f
--define_symbol hci_add_event_handler=0x0000a581
--define_symbol hci_power_control=0x0000ad1d
--define_symbol hci_register_acl_packet_handler=0x0000aed1
--define_symbol kv_commit=0x0000b645
--define_symbol kv_get=0x0000b6a1
--define_symbol kv_init=0x0000b6ad
--define_symbol kv_init_backend=0x0000b72d
--define_symbol kv_put=0x0000b741
--define_symbol kv_remove=0x0000b74d
--define_symbol kv_remove_all=0x0000b781
--define_symbol kv_value_modified=0x0000b7b1
--define_symbol kv_value_modified_of_key=0x0000b7cd
--define_symbol kv_visit=0x0000b7d9
--define_symbol l2cap_add_event_handler=0x0000b869
--define_symbol l2cap_can_send_packet_now=0x0000b879
--define_symbol l2cap_create_le_credit_based_connection_request=0x0000ba35
--define_symbol l2cap_credit_based_send=0x0000bb79
--define_symbol l2cap_credit_based_send_continue=0x0000bba5
--define_symbol l2cap_disconnect=0x0000bc21
--define_symbol l2cap_get_le_credit_based_connection_credits=0x0000be71
--define_symbol l2cap_get_peer_mtu_for_local_cid=0x0000be8d
--define_symbol l2cap_init=0x0000c261
--define_symbol l2cap_le_send_flow_control_credit=0x0000c357
--define_symbol l2cap_max_le_mtu=0x0000c661
--define_symbol l2cap_register_packet_handler=0x0000c789
--define_symbol l2cap_register_service=0x0000c795
--define_symbol l2cap_request_can_send_now_event=0x0000c8a5
--define_symbol l2cap_request_connection_parameter_update=0x0000c8bf
--define_symbol l2cap_send_echo_request=0x0000cd99
--define_symbol l2cap_unregister_service=0x0000ce59
--define_symbol le_device_db_add=0x0000ceb1
--define_symbol le_device_db_find=0x0000cf89
--define_symbol le_device_db_from_key=0x0000cfb5
--define_symbol le_device_db_iter_cur=0x0000cfbd
--define_symbol le_device_db_iter_cur_key=0x0000cfc1
--define_symbol le_device_db_iter_init=0x0000cfc5
--define_symbol le_device_db_iter_next=0x0000cfcd
--define_symbol le_device_db_remove_key=0x0000cff3
--define_symbol ll_aes_encrypt=0x0000d021
--define_symbol ll_config=0x0000d09d
--define_symbol ll_free=0x0000d0d3
--define_symbol ll_get_heap_free_size=0x0000d0dd
--define_symbol ll_hint_on_ce_len=0x0000d0f1
--define_symbol ll_legacy_adv_set_interval=0x0000d129
--define_symbol ll_malloc=0x0000d139
--define_symbol ll_query_timing_info=0x0000d271
--define_symbol ll_register_hci_acl_previewer=0x0000d2bd
--define_symbol ll_scan_set_fixed_channel=0x0000d321
--define_symbol ll_set_adv_access_address=0x0000d539
--define_symbol ll_set_adv_coded_scheme=0x0000d545
--define_symbol ll_set_conn_acl_report_latency=0x0000d575
--define_symbol ll_set_conn_coded_scheme=0x0000d5a5
--define_symbol ll_set_conn_latency=0x0000d5d1
--define_symbol ll_set_conn_tx_power=0x0000d601
--define_symbol ll_set_def_antenna=0x0000d649
--define_symbol ll_set_initiating_coded_scheme=0x0000d665
--define_symbol ll_set_max_conn_number=0x0000d671
--define_symbol nibble_for_char=0x0001e6f9
--define_symbol platform_32k_rc_auto_tune=0x0001e7a5
--define_symbol platform_32k_rc_tune=0x0001e821
--define_symbol platform_calibrate_32k=0x0001e835
--define_symbol platform_config=0x0001e839
--define_symbol platform_delete_timer=0x0001e95d
--define_symbol platform_enable_irq=0x0001e965
--define_symbol platform_get_current_task=0x0001e99d
--define_symbol platform_get_gen_os_driver=0x0001e9c1
--define_symbol platform_get_heap_status=0x0001e9c9
--define_symbol platform_get_link_layer_interf=0x0001e9e1
--define_symbol platform_get_task_handle=0x0001e9e9
--define_symbol platform_get_timer_counter=0x0001ea09
--define_symbol platform_get_us_time=0x0001ea0d
--define_symbol platform_get_version=0x0001ea11
--define_symbol platform_hrng=0x0001ea19
--define_symbol platform_install_isr_stack=0x0001ea21
--define_symbol platform_install_task_stack=0x0001ea2d
--define_symbol platform_patch_rf_init_data=0x0001ea65
--define_symbol platform_printf=0x0001ea71
--define_symbol platform_raise_assertion=0x0001ea85
--define_symbol platform_rand=0x0001ea99
--define_symbol platform_read_info=0x0001ea9d
--define_symbol platform_read_persistent_reg=0x0001eacd
--define_symbol platform_reset=0x0001eadd
--define_symbol platform_set_abs_timer=0x0001eb01
--define_symbol platform_set_evt_callback=0x0001eb05
--define_symbol platform_set_evt_callback_table=0x0001eb19
--define_symbol platform_set_irq_callback=0x0001eb25
--define_symbol platform_set_irq_callback_table=0x0001eb41
--define_symbol platform_set_rf_clk_source=0x0001eb4d
--define_symbol platform_set_rf_init_data=0x0001eb59
--define_symbol platform_set_rf_power_mapping=0x0001eb65
--define_symbol platform_set_timer=0x0001eb71
--define_symbol platform_shutdown=0x0001eb75
--define_symbol platform_switch_app=0x0001eb79
--define_symbol platform_trace_raw=0x0001eba5
--define_symbol platform_write_persistent_reg=0x0001ebbd
--define_symbol printf_hexdump=0x0001ed71
--define_symbol pvPortMalloc=0x0001f865
--define_symbol pvTaskIncrementMutexHeldCount=0x0001f94d
--define_symbol pvTimerGetTimerID=0x0001f965
--define_symbol pxPortInitialiseStack=0x0001f991
--define_symbol reverse_128=0x0001fb71
--define_symbol reverse_24=0x0001fb77
--define_symbol reverse_256=0x0001fb7d
--define_symbol reverse_48=0x0001fb83
--define_symbol reverse_56=0x0001fb89
--define_symbol reverse_64=0x0001fb8f
--define_symbol reverse_bd_addr=0x0001fb95
--define_symbol reverse_bytes=0x0001fb9b
--define_symbol sm_add_event_handler=0x0001fe89
--define_symbol sm_address_resolution_lookup=0x0001ffe1
--define_symbol sm_authenticated=0x0002035d
--define_symbol sm_authorization_decline=0x0002036b
--define_symbol sm_authorization_grant=0x0002038b
--define_symbol sm_authorization_state=0x000203ab
--define_symbol sm_bonding_decline=0x000203c5
--define_symbol sm_config=0x00020821
--define_symbol sm_config_conn=0x00020839
--define_symbol sm_encryption_key_size=0x000209ef
--define_symbol sm_just_works_confirm=0x00020f75
--define_symbol sm_le_device_key=0x000212c1
--define_symbol sm_passkey_input=0x00021357
--define_symbol sm_private_random_address_generation_get=0x00021711
--define_symbol sm_private_random_address_generation_get_mode=0x00021719
--define_symbol sm_private_random_address_generation_set_mode=0x00021725
--define_symbol sm_private_random_address_generation_set_update_period=0x0002174d
--define_symbol sm_register_external_ltk_callback=0x00021889
--define_symbol sm_register_oob_data_callback=0x00021895
--define_symbol sm_request_pairing=0x000218a1
--define_symbol sm_send_security_request=0x00022377
--define_symbol sm_set_accepted_stk_generation_methods=0x0002239d
--define_symbol sm_set_authentication_requirements=0x000223a9
--define_symbol sm_set_encryption_key_size_range=0x000223b5
--define_symbol sscanf_bd_addr=0x00022711
--define_symbol sysSetPublicDeviceAddr=0x00022ac5
--define_symbol uuid128_to_str=0x0002324d
--define_symbol uuid_add_bluetooth_prefix=0x000232a5
--define_symbol uuid_has_bluetooth_prefix=0x000232c5
--define_symbol uxListRemove=0x000232e1
--define_symbol uxQueueMessagesWaiting=0x00023309
--define_symbol uxQueueMessagesWaitingFromISR=0x00023331
--define_symbol uxQueueSpacesAvailable=0x0002334d
--define_symbol uxTaskGetStackHighWaterMark=0x00023379
--define_symbol uxTaskPriorityGet=0x00023399
--define_symbol uxTaskPriorityGetFromISR=0x000233b5
--define_symbol vListInitialise=0x0002346f
--define_symbol vListInitialiseItem=0x00023485
--define_symbol vListInsert=0x0002348b
--define_symbol vListInsertEnd=0x000234bb
--define_symbol vPortEndScheduler=0x000234d5
--define_symbol vPortEnterCritical=0x00023501
--define_symbol vPortExitCritical=0x00023545
--define_symbol vPortFree=0x00023579
--define_symbol vPortSuppressTicksAndSleep=0x0002360d
--define_symbol vPortValidateInterruptPriority=0x00023735
--define_symbol vQueueDelete=0x00023791
--define_symbol vQueueWaitForMessageRestricted=0x000237bd
--define_symbol vTaskDelay=0x00023805
--define_symbol vTaskInternalSetTimeOutState=0x00023851
--define_symbol vTaskMissedYield=0x00023861
--define_symbol vTaskPlaceOnEventList=0x0002386d
--define_symbol vTaskPlaceOnEventListRestricted=0x000238a5
--define_symbol vTaskPriorityDisinheritAfterTimeout=0x000238e5
--define_symbol vTaskPrioritySet=0x00023991
--define_symbol vTaskResume=0x00023a59
--define_symbol vTaskStartScheduler=0x00023add
--define_symbol vTaskStepTick=0x00023b6d
--define_symbol vTaskSuspend=0x00023b9d
--define_symbol vTaskSuspendAll=0x00023c59
--define_symbol vTaskSwitchContext=0x00023c69
--define_symbol xPortStartScheduler=0x00023d11
--define_symbol xQueueAddToSet=0x00023dd9
--define_symbol xQueueCreateCountingSemaphore=0x00023dfd
--define_symbol xQueueCreateCountingSemaphoreStatic=0x00023e39
--define_symbol xQueueCreateMutex=0x00023e7d
--define_symbol xQueueCreateMutexStatic=0x00023e93
--define_symbol xQueueCreateSet=0x00023ead
--define_symbol xQueueGenericCreate=0x00023eb5
--define_symbol xQueueGenericCreateStatic=0x00023f01
--define_symbol xQueueGenericReset=0x00023f69
--define_symbol xQueueGenericSend=0x00023ff5
--define_symbol xQueueGenericSendFromISR=0x00024161
--define_symbol xQueueGiveFromISR=0x00024221
--define_symbol xQueueGiveMutexRecursive=0x000242c5
--define_symbol xQueueIsQueueEmptyFromISR=0x00024305
--define_symbol xQueueIsQueueFullFromISR=0x00024329
--define_symbol xQueuePeek=0x00024351
--define_symbol xQueuePeekFromISR=0x00024479
--define_symbol xQueueReceive=0x000244e5
--define_symbol xQueueReceiveFromISR=0x00024611
--define_symbol xQueueRemoveFromSet=0x000246a5
--define_symbol xQueueSelectFromSet=0x000246c7
--define_symbol xQueueSelectFromSetFromISR=0x000246d9
--define_symbol xQueueSemaphoreTake=0x000246ed
--define_symbol xQueueTakeMutexRecursive=0x00024859
--define_symbol xTaskCheckForTimeOut=0x0002489d
--define_symbol xTaskCreate=0x0002490d
--define_symbol xTaskCreateStatic=0x00024969
--define_symbol xTaskGetCurrentTaskHandle=0x000249d9
--define_symbol xTaskGetSchedulerState=0x000249e5
--define_symbol xTaskGetTickCount=0x00024a01
--define_symbol xTaskGetTickCountFromISR=0x00024a0d
--define_symbol xTaskIncrementTick=0x00024a1d
--define_symbol xTaskPriorityDisinherit=0x00024ae9
--define_symbol xTaskPriorityInherit=0x00024b7d
--define_symbol xTaskRemoveFromEventList=0x00024c11
--define_symbol xTaskResumeAll=0x00024c91
--define_symbol xTaskResumeFromISR=0x00024d59
--define_symbol xTimerCreate=0x00024de5
--define_symbol xTimerCreateStatic=0x00024e19
--define_symbol xTimerCreateTimerTask=0x00024e51
--define_symbol xTimerGenericCommand=0x00024ebd
--define_symbol xTimerGetExpiryTime=0x00024f2d
--define_symbol xTimerGetTimerDaemonTaskHandle=0x00024f4d
