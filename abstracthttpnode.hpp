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

#ifndef ABSTRACTHTTPNODE_HPP
#define ABSTRACTHTTPNODE_HPP

#include "network_global.hpp"
#include <QObject>

namespace Nuria {

class NURIA_NETWORK_EXPORT AbstractHttpNode : public QObject {
	Q_OBJECT
public:
	explicit AbstractHttpNode (QObject *parent = 0);
	
	
	/**
	 * Returns \c true when this node has a valid parent node.
	 */
	bool isChild () const;
	
	/**
	 * Returns the parent node this node is associated to. If this node
	 * has no parent, \c 0 is returned.
	 */
	AbstractHttpNode *parentNode () const;
	
	
signals:
	
public slots:
	
};
}

#endif // ABSTRACTHTTPNODE_HPP
