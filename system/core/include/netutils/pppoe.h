/*
 * Copyright 2010, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _NETUTILS_PPPOE_H_
#define _NETUTILS_PPPOE_H_

__BEGIN_DECLS

typedef struct {
	const char *interface;
	const char *username;
	const char *password;
	int lcp_echo_interval;
	int lcp_echo_failure;
	int mtu;
	int mru;
	int timeout;
	int mss;
} pppoe_config;

const char INTERFACE_PROP_NAME[] = "net.pppoe.interface";
const char USERNAME_PROP_NAME[] = "net.pppoe.username";
const char PASSWORD_PROP_NAME[] = "net.pppoe.password";
const char LCP_ECHO_INTERVAL_PROP_NAME[] = "net.pppoe.lcp_echo_interval";
const char LCP_ECHO_FAILURE_PROP_NAME[] = "net.pppoe.lcp_echo_failure";
const char MTU_PROP_NAME[] = "net.pppoe.mtu";
const char MRU_PROP_NAME[] = "net.pppoe.mru";
const char TIMEOUT_PROP_NAME[] = "net.pppoe.timeout";
const char MSS_PROP_NAME[] = "net.pppoe.mss";
const char PPPOE_STATE_PROP_NAME[] = "net.pppoe.state";
const char PPPOE_RESULT_PROP_NAME[] = "net.pppoe.result";

__END_DECLS

#endif /* _NETUTILS_PPPOE_H_ */
