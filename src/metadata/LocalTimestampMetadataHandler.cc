/*
 * Copyright 2016 Hewlett Packard Enterprise Development LP
 *
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "metadata/LocalTimestampMetadataHandler.h"

#include <factory/Factory.h>

#include <cassert>

#include <string>

#include "workload/Application.h"
#include "event/Simulator.h"
#include "types/Packet.h"

LocalTimestampMetadataHandler::LocalTimestampMetadataHandler(
    Json::Value _settings)
    : MetadataHandler(_settings) {}

LocalTimestampMetadataHandler::~LocalTimestampMetadataHandler() {}

void LocalTimestampMetadataHandler::packetInjection(Application* _app,
                                                    Packet* _packet) {
  _packet->setMetadata(gSim->time());
}

void LocalTimestampMetadataHandler::packetArrival(Packet* _packet) {
  _packet->setMetadata(gSim->time());
}

registerWithFactory("local_timestamp", MetadataHandler,
                    LocalTimestampMetadataHandler, METADATAHANDLER_ARGS);
