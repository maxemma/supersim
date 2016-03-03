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
#ifndef NETWORK_UNO_INJECTIONFUNCTIONFACTORY_H_
#define NETWORK_UNO_INJECTIONFUNCTIONFACTORY_H_

#include <json/json.h>
#include <prim/prim.h>

#include <string>
#include <vector>

#include "event/Component.h"
#include "interface/Interface.h"
#include "network/InjectionFunctionFactory.h"

namespace Uno {

class InjectionFunctionFactory : public ::InjectionFunctionFactory {
 public:
  InjectionFunctionFactory();
  ~InjectionFunctionFactory();
  InjectionFunction* createInjectionFunction(
      const std::string& _name, const Component* _parent, Interface* _interface,
      Json::Value _settings);
};

}  // namespace Uno

#endif  // NETWORK_UNO_INJECTIONFUNCTIONFACTORY_H_