//
//  CommandNode.h
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#ifndef __CthulfuLanguage__CommandNode__
#define __CthulfuLanguage__CommandNode__
#include "Node.h"
#include "PrimitiveCommandNode.h"
#include "RepeatCommandNode.h"
#include "ConditionalCommandNode.h"
class CommandNode : public Node {
public:
	CommandNode()
	{
		CCLOG("CommandNode:create");
	}
	virtual ~CommandNode()
	{
		CCLOG("CommandNode:delete");
	}
	void parse(Context *context) throw(CthulfuException);
};
#endif /* defined(__CthulfuLanguage__CommandNode__) */
