/* Copyright (c) 2014, The Nuria Project
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *    1. The origin of this software must not be misrepresented; you must not
 *       claim that you wrote the original software. If you use this software
 *       in a product, an acknowledgment in the product documentation would be
 *       appreciated but is not required.
 *    2. Altered source versions must be plainly marked as such, and must not be
 *       misrepresented as being the original software.
 *    3. This notice may not be removed or altered from any source
 *       distribution.
 */

#include "httptransport.hpp"

Nuria::HttpTransport::HttpTransport (QObject *parent)
	: QIODevice (parent)
{
	
}

Nuria::HttpTransport::~HttpTransport () {
	
}

Nuria::HttpTransport::Type Nuria::HttpTransport::type () const {
	return Custom;
}

bool Nuria::HttpTransport::isSecure () const {
	return false;
}

QHostAddress Nuria::HttpTransport::localAddress () const {
	return QHostAddress::Null;
}

quint16 Nuria::HttpTransport::localPort () const {
	return 0;
}

QHostAddress Nuria::HttpTransport::peerAddress () const {
	return QHostAddress::Null;
}

quint16 Nuria::HttpTransport::peerPort () const {
	return 0;
}

bool Nuria::HttpTransport::flush () {
	return true;
}