//
//  RepeatCommandNode.h
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#ifndef __CthulfuLanguage__RepeatCommandNode__
#define __CthulfuLanguage__RepeatCommandNode__

#include "Node.h"
class RepeatCommandNode : public Node {
public:
	void parse(Context *context) throw(CthulfuException);

	RepeatCommandNode()
	{
		CCLOG("RepeatCommandNode:create");
	}
	virtual ~RepeatCommandNode()
	{
		CCLOG("RepeatCommandNode:delete");
	}
};


#endif /* defined(__CthulfuLanguage__RepeatCommandNode__) */
