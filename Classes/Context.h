//
//  Context.h
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#ifndef __CthulfuLanguage__Context__
#define __CthulfuLanguage__Context__
#include "cocos2d.h"
#include "CthulfuException.h"
/**
 * 構文解析クラス
 */
class Context{
public:
	bool hasNextToken();
	bool setNextToken();
	std::string getCurrentToken();
	void skipToken(const std::string &token) throw (CthulfuException);
	void execute(cocos2d::CCNode* node);
	void createCCLabelTTF();
	void calculation(int num);
	std::list<char>* getCharList(){ return &mCharList; }
	Context(const char* text);
	~Context();
private:
	std::vector<std::string> mTokenList;
	//std::string mCurrentToken;
	std::list<char> mCharList;
	CC_SYNTHESIZE(int  , mIndex , Index);
	CC_SYNTHESIZE_READONLY(cocos2d::CCArray*, mActions , Actions);
	CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF* , mLabel , Label);
	CC_SYNTHESIZE(int , mMemoryNum , MemoryNum);
};

#endif /* defined(__CthulfuLanguage__Context__) */
