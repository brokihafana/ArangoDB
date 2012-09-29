////////////////////////////////////////////////////////////////////////////////
/// @brief connection endpoints
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2010-2011 triagens GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Jan Steemann
/// @author Copyright 2012, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_FYN_REST_ENDPOINT_BASE_H
#define TRIAGENS_FYN_REST_ENDPOINT_BASE_H 1

#include <Basics/Common.h>
#include <Basics/StringUtils.h>

#ifdef TRI_HAVE_LINUX_SOCKETS
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/file.h>
#endif 


////////////////////////////////////////////////////////////////////////////////
// Base Class for endpoints. An endpoint (currently) consists of:
// 1) Wire Protocol layer (e.g. IP)
// 2) Transport Layer (e.g TCP) 
// 3) A Protocol e.g. HTTP
// 4) Whether or not the data sent if encrpyted
////////////////////////////////////////////////////////////////////////////////


// -----------------------------------------------------------------------------
// --SECTION--                                                          Endpoint
// -----------------------------------------------------------------------------

namespace triagens {
  namespace rest {

////////////////////////////////////////////////////////////////////////////////
/// @brief endpoint specification
////////////////////////////////////////////////////////////////////////////////

    class EndpointBase {

// -----------------------------------------------------------------------------
// --SECTION--                                                          typedefs
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Rest
/// @{
////////////////////////////////////////////////////////////////////////////////
      
      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief default port number if none specified
////////////////////////////////////////////////////////////////////////////////

        static const uint16_t _defaultPort;

////////////////////////////////////////////////////////////////////////////////
/// @brief default host if none specified
////////////////////////////////////////////////////////////////////////////////

        static const string _defaultHost;
      
////////////////////////////////////////////////////////////////////////////////
/// @brief endpoint types
////////////////////////////////////////////////////////////////////////////////

        enum EndpointType {
          ENDPOINT_SERVER, // used when building a server
          ENDPOINT_CLIENT  // used when building a client
        };

////////////////////////////////////////////////////////////////////////////////
/// @brief endpoint types
////////////////////////////////////////////////////////////////////////////////

        // the socket type, e.g. a file system domain or an internet domain
        enum DomainType {
          ENDPOINT_UNKNOWN_DOMAIN = 0, // used to for determining errors
          ENDPOINT_UNIX_DOMAIN, // under windows this would not be available
          ENDPOINT_IPV4_DOMAIN, // internet domain using IP4 addressing
          ENDPOINT_IPV6_DOMAIN // internet domain using IP6 addressing
        };

////////////////////////////////////////////////////////////////////////////////
/// @brief protocols used for endpoints
////////////////////////////////////////////////////////////////////////////////

        enum ProtocolType {
          PROTOCOL_UNKNOWN,
          PROTOCOL_HTTP
        };

////////////////////////////////////////////////////////////////////////////////
/// @brief encryption used when talking to endpoint
////////////////////////////////////////////////////////////////////////////////
        
        enum EncryptionType {
          ENCRYPTION_NONE = 0, 
          ENCRYPTION_SSL
        };

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                        constructors / destructors
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Rest
/// @{
////////////////////////////////////////////////////////////////////////////////

      protected:

////////////////////////////////////////////////////////////////////////////////
/// @brief creates an endpoint
////////////////////////////////////////////////////////////////////////////////

        EndpointBase (const EndPointType endpointType, 
                      const DomainType domainType, 
                      const ProtocolType protocolType, 
                     const EncryptionType encryptionType,
                     const std::string& specification);

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief destroys an endpoint
////////////////////////////////////////////////////////////////////////////////
      
        virtual ~EndpointBase () {
        }

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                    public methods
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Rest
/// @{
////////////////////////////////////////////////////////////////////////////////
    
      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief creates a server endpoint from a string value
////////////////////////////////////////////////////////////////////////////////

        static Endpoint* serverFactory (const std::string&);

////////////////////////////////////////////////////////////////////////////////
/// @brief creates a client endpoint from a string value
////////////////////////////////////////////////////////////////////////////////

        static Endpoint* clientFactory (const std::string&);

////////////////////////////////////////////////////////////////////////////////
/// @brief creates an endpoint from a string value
////////////////////////////////////////////////////////////////////////////////

        static Endpoint* factory (const Type type, 
                                  const std::string&);

////////////////////////////////////////////////////////////////////////////////
/// @brief compare two endpoints
////////////////////////////////////////////////////////////////////////////////

        bool operator== (Endpoint const &) const;

////////////////////////////////////////////////////////////////////////////////
/// @brief return the default endpoint
////////////////////////////////////////////////////////////////////////////////

        static const std::string getDefaultEndpoint ();

////////////////////////////////////////////////////////////////////////////////
/// @brief connect the endpoint
////////////////////////////////////////////////////////////////////////////////
        
        virtual int connect (double, double) = 0; 

////////////////////////////////////////////////////////////////////////////////
/// @brief disconnect the endpoint
////////////////////////////////////////////////////////////////////////////////
        
        virtual void disconnect () = 0; 

////////////////////////////////////////////////////////////////////////////////
/// @brief init an incoming connection
////////////////////////////////////////////////////////////////////////////////

        virtual bool initIncoming (socket_t) = 0;

////////////////////////////////////////////////////////////////////////////////
/// @brief set socket timeout
////////////////////////////////////////////////////////////////////////////////
        
        virtual void setTimeout (socket_t, double); 

////////////////////////////////////////////////////////////////////////////////
/// @brief initialise socket flags
////////////////////////////////////////////////////////////////////////////////
        
        virtual bool setSocketFlags (socket_t); 

////////////////////////////////////////////////////////////////////////////////
/// @brief return whether the endpoint is connected
////////////////////////////////////////////////////////////////////////////////

        bool isConnected () const {
          return _connected;
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief get the type of an endpoint
////////////////////////////////////////////////////////////////////////////////

        Type getEndPointType () const {
          return _endpointType;
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief get the domain type of an endpoint
////////////////////////////////////////////////////////////////////////////////

        DomainType getDomainType () const {
          return _domainType;
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief get the protocol of an endpoint
////////////////////////////////////////////////////////////////////////////////

        Protocol getProtocol () const {
          return _protocol;
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief get the encryption used
////////////////////////////////////////////////////////////////////////////////

        Encryption getEncryption () const {
          return _encryption;
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief get the original endpoint specification
////////////////////////////////////////////////////////////////////////////////

        std::string getSpecification () const {
          return _specification;
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief get endpoint domain
////////////////////////////////////////////////////////////////////////////////

        virtual int getDomain () const = 0;

////////////////////////////////////////////////////////////////////////////////
/// @brief get port number
////////////////////////////////////////////////////////////////////////////////

        virtual int getPort () const = 0;

////////////////////////////////////////////////////////////////////////////////
/// @brief get host name
////////////////////////////////////////////////////////////////////////////////

        virtual std::string getHost () const = 0;

////////////////////////////////////////////////////////////////////////////////
/// @brief get address
////////////////////////////////////////////////////////////////////////////////

        virtual std::string getHostString () const = 0;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                               protected variables
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Rest
/// @{
////////////////////////////////////////////////////////////////////////////////

      protected:

////////////////////////////////////////////////////////////////////////////////
/// @brief whether or not the endpoint is connected
////////////////////////////////////////////////////////////////////////////////

        bool _connected;

////////////////////////////////////////////////////////////////////////////////
/// @brief the actual socket
////////////////////////////////////////////////////////////////////////////////

        socket_t _socket;

////////////////////////////////////////////////////////////////////////////////
/// @brief endpoint type
////////////////////////////////////////////////////////////////////////////////
      
        Type _endpointType;

////////////////////////////////////////////////////////////////////////////////
/// @brief endpoint domain type
////////////////////////////////////////////////////////////////////////////////
      
        DomainType _domainType;

////////////////////////////////////////////////////////////////////////////////
/// @brief protocol used
////////////////////////////////////////////////////////////////////////////////

        Protocol _protocol;

////////////////////////////////////////////////////////////////////////////////
/// @brief encryption used
////////////////////////////////////////////////////////////////////////////////

        Encryption _encryption;

////////////////////////////////////////////////////////////////////////////////
/// @brief original endpoint specification
////////////////////////////////////////////////////////////////////////////////

        std::string _specification;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

    };    

  }
}

#endif

// Local Variables:
// mode: outline-minor
// outline-regexp: "^\\(/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|// --SECTION--\\|/// @\\}\\)"
// End: