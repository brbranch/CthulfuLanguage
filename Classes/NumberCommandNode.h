//
//  NumberCommandNode.h
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#ifndef __CthulfuLanguage__NumberCommandNode__
#define __CthulfuLanguage__NumberCommandNode__
#include "Node.h"
typedef enum _CalcType {
	calc_plus,
	calc_minus,
	calc_times,
}CalcType;

class NumberCommandNode : public Node {
public:
	void parse(Context *context) throw(CthulfuException);

	NumberCommandNode() : mNum(1), mCulcType(calc_plus)
	{
		CCLOG("NumberCommandNode::create");
	};
	virtual ~NumberCommandNode()
	{
		CCLOG("NumberCommandNode:delete");
	}
private:
	void calc(int num);

	CC_SYNTHESIZE_READONLY(int, mNum, Number);
	CalcType mCulcType;
};

#endif /* defined(__CthulfuLanguage__NumberCommandNode__) */
