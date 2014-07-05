//
//  Node.h
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#ifndef CthulfuLanguage_Node_h
#define CthulfuLanguage_Node_h
#include "cocos2d.h"
#include "CthulfuException.h"
#include "Context.h"
class Node : public cocos2d::CCObject {
public:
	virtual void parse(Context *context) throw(CthulfuException) = 0;

	virtual ~Node()
	{
	};
};

#endif
