/*
 * BLEServiceMap.cpp
 *
 *  Created on: Jun 22, 2017
 *      Author: kolban
 */

#include <stdio.h>
#include <iomanip>
#include "BLEService.h"


/**
 * @brief Return the service by UUID.
 * @param [in] UUID The UUID to look up the service.
 * @return The characteristic.
 */
BLEService* BLEServiceMap::getByUUID(BLEUUID uuid, uint8_t inst_id) {
	for (auto &myPair : m_uuidMap) {
		if (myPair.first->getUUID().equals(uuid)) {
			return myPair.first;
		}
	}
	//return m_uuidMap.at(uuid.toString());
	return nullptr;
} // getByUUID


/**
 * @brief Set the service by UUID.
 * @param [in] uuid The uuid of the service.
 * @param [in] characteristic The service to cache.
 * @return N/A.
 */
void BLEServiceMap::setByUUID(BLEUUID uuid, BLEService* service) {
	m_uuidMap.insert(std::pair<BLEService*, std::string>(service, uuid.toString()));
} // setByUUID




/**
 * @brief Return a string representation of the service map.
 * @return A string representation of the service map.
 */
std::string BLEServiceMap::toString() {
	std::string res;
	char hex[5];
	for (auto &myPair: m_handleMap) {
		res += "handle: 0x";
		snprintf(hex, sizeof(hex), "%04x", myPair.first);
		res += hex;
		res += ", uuid: " + myPair.second->getUUID().toString() + "\n";
	}
	return res;
} // toString