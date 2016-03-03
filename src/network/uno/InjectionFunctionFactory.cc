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
#include "network/uno/InjectionFunctionFactory.h"

#include <cassert>

#include "network/uno/AnyInjectionFunction.h"
#include "network/InjectionFunction.h"

namespace Uno {

InjectionFunctionFactory::InjectionFunctionFactory()
    : ::InjectionFunctionFactory() {}

InjectionFunctionFactory::~InjectionFunctionFactory() {}

InjectionFunction* InjectionFunctionFactory::createInjectionFunction(
    const std::string& _name, const Component* _parent, Interface* _interface,
    Json::Value _settings) {
  std::string algorithm = _settings["algorithm"].asString();
  u32 latency = _settings["latency"].asUInt();

  if (algorithm == "any") {
    return new Uno::AnyInjectionFunction(
        _name, _parent, _interface, latency);
  } else {
    fprintf(stderr, "Unknown injection algorithm: '%s'\n", algorithm.c_str());
    assert(false);
  }
}

}  // namespace Uno