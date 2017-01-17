/****************************************************************************/
/// @file    Manager.cc
/// @author  Mani Amoozadeh <maniam@ucdavis.edu>
/// @author  second author name
/// @date    August 2013
///
/****************************************************************************/
// VENTOS, Vehicular Network Open Simulator; see http:?
// Copyright (C) 2013-2015
/****************************************************************************/
//
// This file is part of VENTOS.
// VENTOS is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "bicycle/03_Manager.h"

namespace VENTOS {

const simsignalwrap_t ApplBikeManager::mobilityStateChangedSignal = simsignalwrap_t(MIXIM_SIGNAL_MOBILITY_CHANGE_NAME);

Define_Module(VENTOS::ApplBikeManager);

ApplBikeManager::~ApplBikeManager()
{

}


void ApplBikeManager::initialize(int stage)
{
    super::initialize(stage);

	if (stage == 0)
	{

        // findHost()->subscribe(mobilityStateChangedSignal, this);
	}
}


void ApplBikeManager::finish()
{
    super::finish();

    //findHost()->unsubscribe(mobilityStateChangedSignal, this);
}


void ApplBikeManager::receiveSignal(omnetpp::cComponent* source, omnetpp::simsignal_t signalID, cObject* obj, cObject* details)
{
    Enter_Method_Silent();

    if (signalID == mobilityStateChangedSignal)
    {
        handlePositionUpdate(obj);
    }
}


void ApplBikeManager::handleSelfMsg(omnetpp::cMessage* msg)
{
    super::handleSelfMsg(msg);
}


void ApplBikeManager::handleLowerMsg(omnetpp::cMessage* msg)
{
    if (msg->getKind() == TYPE_BEACON_VEHICLE)
    {
        BeaconVehicle* wsm = dynamic_cast<BeaconVehicle*>(msg);
        ASSERT(wsm);
    }
    else if (msg->getKind() == TYPE_BEACON_RSU)
    {
        BeaconRSU* wsm = dynamic_cast<BeaconRSU*>(msg);
        ASSERT(wsm);
    }

    delete msg;
}


// is called, every time the position of vehicle changes
void ApplBikeManager::handlePositionUpdate(cObject* obj)
{
    super::handlePositionUpdate(obj);

    ChannelMobilityPtrType const mobility = omnetpp::check_and_cast<ChannelMobilityPtrType>(obj);
    curPosition = mobility->getCurrentPosition();
}


void ApplBikeManager::onBeaconVehicle(BeaconVehicle* wsm)
{
    // pass it down
    //super::onBeaconVehicle(wsm);

}


void ApplBikeManager::onBeaconRSU(BeaconRSU* wsm)
{
    // pass it down
    //super::onBeaconRSU(wsm);
}

}
