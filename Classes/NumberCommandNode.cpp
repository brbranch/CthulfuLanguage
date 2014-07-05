//
//  NumberCommandNode.cpp
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#include "NumberCommandNode.h"
void NumberCommandNode::parse(Context *context) throw (CthulfuException) {
	context->skipToken("イア！イア！");
	while (true) {
		std::string current = context->getCurrentToken();
		if (current.compare("フタグン！") == 0) {
			context->skipToken(current);
			break;
		}
		if (context->hasNextToken() == false) {
			CCLOG("惜しいです・・・フタグン！と唱え損ねたばかりに・・・");
			CCLOG("「・・・莫迦め！ウォーランはもう死んだわ！」");
			throw CthulfuException();
		}
		if (current.compare("イグ！") == 0) {
			this->calc(1);
		}
		else if (current.compare("イタカ！") == 0) {
			this->calc(2);
		}
		else if (current.compare("ハスタア！") == 0) {
			this->calc(3);
		}
		else if (current.compare("アブホース！") == 0) {
			this->calc(5);
		}
		else if (current.compare("チャウグナル・ファウグン！") == 0) {
			this->calc(7);
		}
		else if (current.compare("ニャル・シュタン！") == 0) {
			this->calc(11);
		}
		else if (current.compare("ニャル・ガシャンナ！") == 0) {
			this->calc(13);
		}
		else if (current.compare("シャメッシュ！シャメッシュ！") == 0) {
			this->calc(17);
		}
		else if (current.compare("イア！") == 0) {
			this->calc(10);
		}
		else if (current.compare("イア！イア！") == 0) {
			CCLOG("計算方法変更：足し算");
			mCulcType = calc_plus;
		}
		else if (current.compare("クトゥルフ！") == 0) {
			CCLOG("計算方法変更：かけ算");
			mCulcType = calc_times;
		}
		else if (current.compare("イア・ル・リェー！クトゥルフ・フタグン！") == 0) {
			CCLOG("計算方法変更：ひき算");
			mCulcType = calc_minus;
		}
		else {
			CCLOG("・・・無意味なものが呼ばれた:%s", current.c_str());
		}
		context->setNextToken();
	}
}

void NumberCommandNode::calc(int num) {
	switch (mCulcType) {
		case calc_times:
			mNum *= num;
			CCLOG("%dがかけられます", num);
			break;

		case calc_minus:
			mNum -= num;
			CCLOG("%dが引かれます", num);
			break;

		default:
			mNum += num;
			CCLOG("%dが足されます", num);
			break;
	}
	CCLOG("現在の数字:%d", mNum);
}
