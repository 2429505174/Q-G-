
from numpy import *    ##科学计算库 

class ercheng:
	def __init__(self):
		self.a_=None
		self.b_=None

	def fit(self,x,y):
		assert x.ndim==1,		"仅处理简单线性回归"
		assert len(x)==len(y),		"x y 形状要相同"

		xmean=mean(x)
		ymean=mean(y)

		num=0.0
		d=0.0
		for x1,y1 in zip(x,y):  ##核心两步骤
			num+=(x1-xmean)*(y1-ymean)
			d+=(x1-xmean)**2   
           
		self.a_=num/d   #找到a了
		#print(a)
		self.b_=ymean-self.a_*xmean  #yba -a xba
		return self

	def predict(self,x):
		assert x.ndim==1,"仅处理简单线性回归"
		assert self.a_ is not None and self.b_ is not None,"fit before predict"


		return array([self._predict(x1) for x1 in x])

	def _predict(self,x):
		return self.a_* x+self.b_

