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

#include "httpparser.hpp"

Nuria::HttpParser::HttpParser () {
	
}

Nuria::HttpParser::~HttpParser () {
	
}

bool Nuria::HttpParser::parseFirstLine (const QByteArray &data, QByteArray &verb,
					QByteArray &path, QByteArray &version) {
	// Format: "<VERB> <Path> HTTP/<Version>"
	int endOfVerb = data.indexOf (' ');
	int endOfPath = data.indexOf (' ', endOfVerb + 1);
	
	// Indexes
	int beginOfPath = endOfVerb + 1;
	int beginOfVersion = endOfPath + 1;
	int pathLength = endOfPath - beginOfPath;
	int versionLength = data.length () - beginOfVersion;
	
	// Sanity check
	if (endOfVerb == -1 || endOfPath == -1) {
		return false;
	}
	
	// Shallow copy fields
	verb = QByteArray::fromRawData (data.constData (), endOfVerb);
	path = QByteArray::fromRawData (data.constData () + beginOfPath, pathLength);
	QByteArray rawVersion = QByteArray::fromRawData (data.constData () + beginOfVersion, versionLength);
	
	// Verify fields
	if (verb.isEmpty () || path.isEmpty () || !rawVersion.startsWith ("HTTP/")) {
		return false;
	}
	
	// Shallow copy version string
	beginOfVersion += 5;
	versionLength -= 5;
	version = QByteArray::fromRawData (data.constData () + beginOfVersion, versionLength);
	
	// Done.
	return !version.isEmpty ();
}

bool Nuria::HttpParser::parseHeaderLine (const QByteArray &data, QByteArray &name,
					 QByteArray &value) {
	// Format: "<Name>: <Value>"
	// Note: It's fine for us if there's no space after the colon.
	int endOfName = data.indexOf (':');
	int beginOfValue = endOfName + 1;
	
	// Sanity check
	if (endOfName == -1 || data.length () - beginOfValue < 2) {
		return false;
	}
	
	// Optional space after the colon
	if (data.at (beginOfValue) == ' ') {
		beginOfValue++;
	}
	
	// Shallow copy
	int valueLength = data.length () - beginOfValue;
	name = QByteArray::fromRawData (data.constData (), endOfName);
        value = QByteArray::fromRawData (data.constData () + beginOfValue, valueLength);
	
	// Done.
	return (!name.isEmpty () && !value.isEmpty ());
}

Nuria::HttpClient::HttpVersion Nuria::HttpParser::parseVersion (const QByteArray &version) {
	
	if (version == "1.1") {
		return HttpClient::Http1_1;
	}
	
	if (version == "1.0") {
		return HttpClient::Http1_0;
	}
	
	return HttpClient::HttpUnknown;
}
