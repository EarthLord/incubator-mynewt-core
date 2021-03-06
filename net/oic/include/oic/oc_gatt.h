/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef OC_GATT_H
#define OC_GATT_H

#include "host/ble_uuid.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OC_GATT_SERVICE_UUID    0x9923

int oc_ble_coap_gatt_srv_init(void);
void oc_ble_coap_conn_new(uint16_t conn_handle);
void oc_ble_coap_conn_del(uint16_t conn_handle);

#ifdef __cplusplus
}
#endif

#endif /* OC_GATT_H */

