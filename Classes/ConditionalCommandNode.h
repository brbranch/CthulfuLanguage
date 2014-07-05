//
//  ConditionalCommandNode.h
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#ifndef __CthulfuLanguage__ConditionalCommandNode__
#define __CthulfuLanguage__ConditionalCommandNode__

#include "Node.h"
class ConditionalCommandNode : public Node {
public:
	void parse(Context *context) throw(CthulfuException);

	ConditionalCommandNode() : mIsDone(false)
	{
		CCLOG("ConditionalCommandNode:create");
	}
	virtual ~ConditionalCommandNode()
	{
		CCLOG("ConditionalCommandNode:delete");
	}
private:
	void allSkip(Context *context) throw(CthulfuException);
	bool compare(Context *context, const std::string &current) throw(CthulfuException);

	bool mIsDone;
};


#endif /* defined(__CthulfuLanguage__ConditionalCommandNode__) */
