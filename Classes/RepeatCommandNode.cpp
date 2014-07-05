//
//  RepeatCommandNode.cpp
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#include "RepeatCommandNode.h"
#include "NumberCommandNode.h"
#include "CommandListNode.h"
void RepeatCommandNode::parse(Context *context) throw (CthulfuException) {
	context->skipToken("ティビ・マグヌム・イノミナンドゥム・シグナ！ステラルム！イグラルム！エブファニフォルミス！");
	NumberCommandNode *num = new NumberCommandNode();
	CCLOG("繰り返される");
	int time = 0;
	try {
		num->parse(context);
		time = num->getNumber();
		CCLOG("ーーーーー%d回繰り返される！", time);
		delete num;
	}
	catch (const CthulfuException &e)
	{
		delete num;
		CCLOG("繰り返されるはずだった！");
		throw e;
	}
	int index = context->getIndex();
	for (int i = 0; i < time; i++) {
		Node *node = NULL;
		CCLOG("ーーーーー%d回目！", i);
		try {
			context->setIndex(index);
			node = new CommandListNode();
			node->parse(context);
			delete node;
		}
		catch (const CthulfuException &e)
		{
			CCLOG("ここで中断された。%s", context->getCurrentToken().c_str());
			delete node;
			throw e;
		}
	}
}
