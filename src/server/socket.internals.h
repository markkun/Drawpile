/*******************************************************************************

   Copyright (C) 2006, 2007 M.K.A. <wyrmchild@users.sourceforge.net>

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.

*******************************************************************************/

#ifndef SocketInternals_INCLUDED
#define SocketInternals_INCLUDED

#include "config.h"
#include "socket.porting.h"

#ifdef WIN32
	#define EWOULDBLOCK WSAEWOULDBLOCK
	
	#define EINPROGRESS WSAEINPROGRESS
	#define ENETDOWN WSAENETDOWN
	//#define EMFILE WSAEMFILE
	#define ENOBUFS WSAENOBUFS
	//#define EINTR WSAEINTR
	#define ECONNABORTED WSAECONNABORTED
	#define EADDRNOTAVAIL WSAEADDRNOTAVAIL
	#define EADDRINUSE WSAEADDRINUSE
	//#define EACCES WSAEACCES
	#define ECONNREFUSED WSAECONNREFUSED
	#define ETIMEDOUT WSAETIMEDOUT
	#define ENETUNREACH WSAENETUNREACH
	#define ECONNRESET WSAECONNRESET
	#define ESHUTDOWN WSAESHUTDOWN
	#define EDISCON WSAEDISCON
	#define ENETRESET WSAENETRESET
	#define EAFNOSUPPORT WSAEAFNOSUPPORT
	#define ENOTCONN WSAENOTCONN
	#define EISCONN WSAEISCONN
	#define EALREADY WSAEALREADY
	
	// winows only
	//#define WSA_IO_PENDING
	//#define WSA_OPERATION_ABORTED
	
	// programming errors
	//#define EFAULT WSAEFAULT
	//#define EBADF WSAEBADF
	#define ENOTSOCK WSAENOTSOCK
	#define ENOPROTOOPT WSAENOPROTOOPT
	#define EPROTOTYPE WSAEPROTOTYPE
	#define ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
	#define EOPNOTSUPP WSAEOPNOTSUPP
	#define EPROTONOSUPPORT WSAEPROTONOSUPPORT
	
	#define MSG_NOSIGNAL 0 // the flag isn't used in win32
	
	#define SHUT_RD SD_RECEIVE
	#define SHUT_WR SD_SEND
	#define SHUT_RDWR SD_BOTH
#else
	// not defined in non-win32 systems
	#define INVALID_SOCKET -1
	#define SOCKET_ERROR -1
	
	#ifndef EWOULDBLOCK
		#define EWOULDBLOCK EAGAIN
	#endif
#endif

#endif // SocketInternals_INCLUDED
