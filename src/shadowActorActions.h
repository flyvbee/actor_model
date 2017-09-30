#pragma once
constexpr int shadowActorAction_create_subdomain       = 1 ;
constexpr int shadowActorAction_shutdown_slave_process = 2 ;
constexpr int shadowActorAction_hello_world            = 3;
constexpr int shadowActorAction_partition_input_A      = 4;
constexpr int shadowActorAction_partition_input_B      = 5;
constexpr int shadowActorAction_new_step               = 6;
constexpr int shadowActorAction_update                 = 7;
constexpr int shadowActorAction_compute                = 8;
constexpr int shadowActorAction_check_residual         = 9;
constexpr int shadowActorAction_commit                 = 10;
constexpr int shadowActorAction_revert                 = 11;
constexpr int shadowActorAction_collect_results        = 12;
constexpr int shadowActorAction_say_bye                = 13;