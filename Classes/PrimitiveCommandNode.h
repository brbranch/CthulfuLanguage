//
//  PrimitiveCommandNode.h
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#ifndef __CthulfuLanguage__PrimitiveCommandNode__
#define __CthulfuLanguage__PrimitiveCommandNode__
#include "Node.h"
class PrimitiveCommandNode : public Node {
public:
	PrimitiveCommandNode()
	{
		CCLOG("PrimitiveCommandNode:create");
	}
	virtual ~PrimitiveCommandNode()
	{
		CCLOG("PrimitiveCommandNode:delete");
	}
	void parse(Context *context) throw(CthulfuException);

private:
	int getNum(Context *context) throw(CthulfuException);
	char *createChar(Context *context);
};
#endif /* defined(__CthulfuLanguage__PrimitiveCommandNode__) */
