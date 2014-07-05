//
//  CommandListNode.h
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#ifndef __CthulfuLanguage__CommandListNode__
#define __CthulfuLanguage__CommandListNode__
#include "Node.h"
class CommandListNode : public Node {
public:
	CommandListNode()
	{
		CCLOG("CommandListNode:create");
	}
	virtual ~CommandListNode()
	{
		CCLOG("CommandListNode:delete");
	}

	void parse(Context *context) throw(CthulfuException);
};

#endif /* defined(__CthulfuLanguage__CommandListNode__) */
