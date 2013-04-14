/*! 
@file epSyncUdpSocket.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/epserverengine>
@date February 13, 2012
@brief Synchronous UDP Socket Interface
@version 1.0

@section LICENSE

Copyright (C) 2012  Woong Gyu La <juhgiyo@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

@section DESCRIPTION

An Interface for Synchronous UDP Socket.

*/
#ifndef __EP_SYNC_UDP_SOCKET_H__
#define __EP_SYNC_UDP_SOCKET_H__

#include "epServerEngine.h"
#include "epBaseUdpSocket.h"

namespace epse
{
	class SyncUdpServer;
	/*! 
	@class SyncUdpSocket epSyncUdpSocket.h
	@brief A class for Asynchronous UDP Socket.
	*/
	class EP_SERVER_ENGINE SyncUdpSocket:public BaseUdpSocket
	{
		friend class SyncUdpServer;
	public:
		/*!
		Default Constructor

		Initializes the Socket
		@param[in] callBackObj the callback object
		@param[in] waitTimeMilliSec wait time for Socket Thread to terminate
		@param[in] lockPolicyType The lock policy
		*/
		SyncUdpSocket(ServerCallbackInterface *callBackObj,unsigned int waitTimeMilliSec=WAITTIME_INIFINITE,epl::LockPolicy lockPolicyType=epl::EP_LOCK_POLICY);

		/*!
		Default Destructor

		Destroy the Socket
		*/
		virtual ~SyncUdpSocket();

		
		/*!
		Kill the connection
		*/
		virtual void KillConnection();


	private:	
		friend class BaseServerUDP;

		/*!
		Actually Kill the connection
		*/
		virtual void killConnection();

		
		/*!
		thread loop function
		*/
		virtual void execute();
	
	private:
		/*!
		Default Copy Constructor

		Initializes the SyncUdpSocket
		@param[in] b the second object
		*/
		SyncUdpSocket(const SyncUdpSocket& b):BaseUdpSocket(b)
		{}


		/*!
		Assignment operator overloading
		@param[in] b the second object
		@return the new copied object
		*/
		SyncUdpSocket & operator=(const SyncUdpSocket&b){return *this;}
	};

}

#endif //__EP_SYNC_UDP_SOCKET_H__