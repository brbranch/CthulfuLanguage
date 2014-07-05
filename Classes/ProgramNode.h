//
//  ProgramNode.h
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#ifndef __CthulfuLanguage__ProgramNode__
#define __CthulfuLanguage__ProgramNode__
#include "Node.h"
class ProgramNode : public Node {
public:
	ProgramNode()
	{
		CCLOG("ProgramNode:create");
	}
	virtual ~ProgramNode()
	{
		CCLOG("ProgramNode:delete");
	}
	void parse(Context *context) throw(CthulfuException);
};

#endif /* defined(__CthulfuLanguage__ProgramNode__) */
