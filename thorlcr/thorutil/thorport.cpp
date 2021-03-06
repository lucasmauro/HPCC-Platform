/*##############################################################################

    HPCC SYSTEMS software Copyright (C) 2012 HPCC Systems®.

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

// Thor Port Allocation

#include "platform.h"

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h> 
#include <stdlib.h> 

#include "jlib.hpp"
#include "jdebug.hpp"
#include "jexcept.hpp"
#include "jmutex.hpp"
#include "jset.hpp"
#include "jmisc.hpp"

#include "portlist.h"
#include "thorport.hpp"

// NB: these are offsets from slave/channel start port
#define MPPORT       0
#define WATCHDOGPORT 1
#define DEBUGPORT 2

static unsigned short masterportbase=0;
static unsigned short machineportbase=0;


unsigned short getFixedPort(ThorPortKind category)
{
    return getFixedPort(machineportbase, category);
}

unsigned short getFixedPort(unsigned short machineBase, ThorPortKind category)
{
    return getExternalFixedPort(masterportbase, machineBase, category);
}

unsigned short getExternalFixedPort(unsigned short masterBase, unsigned short machineBase, ThorPortKind category)
{
    if (!masterBase) masterBase = THOR_BASE_PORT;
    if (!machineBase) machineBase = THOR_BASESLAVE_PORT;
    return machineBase + getPortOffset(category);
}
  
void setMachinePortBase(unsigned short base)
{
    machineportbase = base;
}

void setMasterPortBase(unsigned short base)
{
    masterportbase = base;
}

unsigned short getMasterPortBase()
{
    return masterportbase?masterportbase:THOR_BASE_PORT;
}

unsigned short getMachinePortBase()
{
    return machineportbase?machineportbase:THOR_BASESLAVE_PORT;
}

unsigned getPortOffset(ThorPortKind category)
{
    switch (category)
    {
        case TPORT_watchdog:
            return WATCHDOGPORT;
        case TPORT_mp:
            return MPPORT; 
        case TPORT_debug:
            return DEBUGPORT;
        default:
            throwUnexpected();
    }
}
