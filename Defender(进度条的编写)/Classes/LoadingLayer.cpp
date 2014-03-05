#include "LoadingLayer.h"
USING_NS_CC;
bool LoadingLayer::init(){
	bool isRet=false;
	do 
	{
	CC_BREAK_IF(!BaseLayer::init());
	CC_BREAK_IF(!this->setUpdateView());
	CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/longding.png",this,callfuncO_selector(LoadingLayer::loadCallBack));
	isRet=true;
	} while (0);
	return isRet;
}
CCScene* LoadingLayer::scene(){
	CCScene* scene=CCScene::create();
	LoadingLayer* layer=LoadingLayer::create();
	scene->addChild(layer);
	return scene;
}
void LoadingLayer::loadCallBack(CCObject* ped){
	loadingNum++;	 
    CCProgressTimer* pt=(CCProgressTimer*)this->getChildByTag(1);
	float now=pt->getPercentage();
	pt->setPercentage(100/totalNum+now);
	if(loadingNum<totalNum){
		
	}else{
		// �������ʱ����ת����Ӧ�Ľ���
		CCLOG("loading over");
	}
}
LoadingLayer::LoadingLayer(){
	this->loadingNum=0;
	this->totalNum=1;
}
bool LoadingLayer::setUpdateView(){
	bool isRet=false;
	do 
	{
	// ���ý������ı���ͼƬ ���ǰ����ŵ���Ļ�·���1/5��	
    CCSprite* loadbackimg=CCSprite::create("gmbg/lodingbg.png");
	CC_BREAK_IF(!loadbackimg);	
	loadbackimg->setPosition(ccp(getWinSize().width/2+getWinOrigin().x,getWinSize().height/5+getWinOrigin().y));
	this->addChild(loadbackimg,1);
	
	// ��ӽ�����
	CCSprite* loadimg=CCSprite::create("gmbg/longding.png");
	CC_BREAK_IF(!loadimg);	
	CCProgressTimer* pt = CCProgressTimer::create(loadimg);
	pt->setType(kCCProgressTimerTypeBar);// ���óɺ����
	//���Կ����ǰ�������ʾЧ���Ľ���������
	pt->setMidpoint(ccp(0,0)); 
	//  �����趨����������ǰ���ķ���������һ��Ǵ�������
	pt->setBarChangeRate(ccp(1,0));
	//��������ê��
	float tex=getWinSize().width/2+getWinOrigin().x;
	float tey=getWinSize().height/5+getWinOrigin().y-5;
	pt->setPosition(ccp(tex,tey));
	pt->setPercentage(0);
	this->addChild(pt,2,1);

	isRet=true;
	} while (0);
	return isRet;
}