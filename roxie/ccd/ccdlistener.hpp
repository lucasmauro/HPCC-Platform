/*##############################################################################

    HPCC SYSTEMS software Copyright (C) 2013 HPCC Systems®.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
############################################################################## */

#ifndef _CCDLISTENER_INCL
#define _CCDLISTENER_INCL

#include <jlib.hpp>
#include "ccdprotocol.hpp"

extern IHpccProtocolMsgSink *createRoxieProtocolMsgSink(const IpAddress &ip, unsigned short port, unsigned poolSize, bool suspended);

extern IHpccProtocolListener *createRoxieWorkUnitListener(unsigned poolSize, bool suspended);

extern MapStringToMyClass<SharedObject> protocolDlls;
extern MapStringToMyClass<IHpccProtocolPlugin> protocolPlugins;
extern IArrayOf<IHpccProtocolListener> socketListeners;

extern IHpccProtocolPlugin *ensureProtocolPlugin(IHpccProtocolPluginContext &protocolCtx, const char *soname);

extern void disconnectRoxieQueues();
extern void updateAffinity(unsigned __int64 affinity);

#endif
