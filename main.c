#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define   N   20

char getSig()//运算符
{
    char signal[4]={'+','-','x','/'};
    return signal[rand()%4];
}
int random(int a)//随机数
{
	int b;
    b=rand()%a+1;
	return b;
}
int gcd(int x,int y)//辗转相除法
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int answers(int i,int num,int num1,int num2,int num3,int num4,char sig1,char sig2,char sig3,int ran)//生成答案
{
	int question(int i,int ran);
	int ans,maxn,count=0;
	FILE *fp;
	fp=fopen("Answers.txt","a+");
	if(num==1)
	{
		int ans1,ans2;
		switch(sig1)
		{
			case '+':
				ans=num1+num2;
			    fprintf(fp,"题目%d:%d %c %d = %d\n",i,num1,sig1,num2,ans);
			    fclose(fp);break;
			case '-':
				if(num1<num2)question(i,ran);
				else
				{
					ans=num1-num2;
			        fprintf(fp,"题目%d:%d %c %d = %d\n",i,num1,sig1,num2,ans);
			        fclose(fp);
				}break;
			case 'x':
				ans=num1*num2;
			    fprintf(fp,"题目%d:%d %c %d = %d\n",i,num1,sig1,num2,ans);
			    fclose(fp);break;
			case '/':
				maxn=gcd(num1,num2);
				ans1=num1/maxn;
				ans2=num2/maxn;
				count=0;
				while(ans1>ans2)
				{
					ans1=ans1-ans2;
					count++;
				}
				if(count>0)fprintf(fp,"题目%d:%d %c %d = %d'%d/%d\n",i,num1,sig1,num2,count,num1,num2);
				if(count=0)fprintf(fp,"题目%d:%d %c %d = %d/%d\n",i,num1,sig1,num2,num1,num2);
			    fclose(fp);break;
		}
	}
	if(num==2)
	{
		if(sig2=='x'&&sig1!='/')
		{
			int ans1;
			ans1=num2*num3;
			switch(sig1)
		    {
		    	case '+':
		    		ans=num1+ans1;
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,ans);
		    	    fclose(fp);break;
		    	case '-':
		    		if(num1<ans1)question(i,ran);
		    		else
		    		{
					    ans=num1-ans1;
		    		    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,ans);
		    	        fclose(fp);
					}break;
		    	case 'x':
		    		ans=num1*ans1;
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,ans);
		    	    fclose(fp);break;
		    }
		}
		else
		if(sig2=='/'&&sig1!='/')
		{
			int ans1,ans2;
			count=0;
			maxn=gcd(num2,num3);
			ans1=num2/maxn;
			ans2=num3/maxn;
			while(ans1>ans2)
			{
				ans1=ans1-ans2;
				count++;
			}
			switch(sig1)
		    {
		    	case '+':
		    		count=num1+count;
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,count,ans1,ans2);
		    	    fclose(fp);break;
		    	case '-':
		    		if(num1<=count)question(i,ran);
		    		else
		    		{
		    	    	count=num1-count;
		        		int a1,a2;
		        		if(count=1)
		        		{
		        			a1=ans2-ans1;
		        			a2=ans2;
		    			}
		    			else
		    			{
		    				count--;
			    			a1=ans2-ans1;
		        			a2=ans2;
		    			}
		        	}
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,count,ans1,ans2);
		    	    fclose(fp);break;
		    	case 'x':
		    		count=0;
					ans1=num1*num2;
		    		maxn=gcd(ans1,num3);
		    		ans1=ans1/maxn;
		    		ans2=num3/maxn;
		    		while(ans1>ans2)
		    		{
		    			ans1=ans1-ans2;
		    			count++;
					}
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,count,ans1,ans2);
		    	    fclose(fp);break;
		    	case '/':
		    		count=0;
		    		ans2=num2*num3;
		    		maxn=gcd(num1,ans2);
		    		ans1=num1/maxn;
		    		ans2=ans2/maxn;
		    		while(ans1>ans2)
		    		{
		    			ans1=ans1-ans2;
		    			count++;
					}
		    		ans=num1/ans1;
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,count,ans1,ans2);
		    	    fclose(fp);break;
		    }
		}
	    if(sig1=='/')
	    {
	    	int ans1,ans2;
	    	count=0;
	    	switch(sig2)
	    	{
	    		case '+':
	    			maxn=gcd(num1,num2);
	    			ans1=num1/maxn;
	    			ans2=num2/maxn;
	    			count=0;
	    			while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				count++;
					}
					count=count+num3;
					fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,count,ans1,ans2);
					fclose(fp);break;
				case '-':
					maxn=gcd(num1,num2);
	    			ans1=num1/maxn;
	    			ans2=num2/maxn;
	    			count=0;
	    			while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				count++;
					}
					if(count<num3) question(i,ran);
					else
					if(count=num3)
					{
						fprintf(fp,"题目%d:%d %c %d %c %d = %d/%d\n",i,num1,sig1,num2,sig2,num3,ans1,ans2);
						fclose(fp);
					}
					else
					if(count>num3)
					{
						count=count-num3;
						fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,count,ans1,ans2);
						fclose(fp);
					}break;
				case 'x':
					ans1=num1*num3;
					maxn=gcd(ans1,num2);
					ans1=ans1/maxn;
					ans2=num2/maxn;
					count=0;
					while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				count++;
					}
					fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,count,ans1,ans2);
					fclose(fp);break;
				case '/':
					ans2=num2*num3;
					maxn=gcd(num1,ans2);
					ans1=num1/maxn;
					ans2=ans2/maxn;
					count=0;
					while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				count++;
					}
					fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,count,ans1,ans2);
					fclose(fp);break;
			}
		}
		else
		if(sig1='+')
	    {
	    	int ans1,ans2;
	    	count=0;
	    	switch(sig2)
    		{
	    		case '+':
	    			ans=num1+num2+num3;
	    		    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,ans);
	    		    fclose(fp);break;
    			case '-':
    				if(num1+num2<num3)question(i,ran);
    				else
    				{
    					ans=num1+num2-num3;
	    		        fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,ans);
	    		        fclose(fp);break;
					}
	    	}
	    }
	    else
	    if(sig1='-')
	    {
	    	switch(sig2)
    		{
	    		case '+':
	    			if(num1-num2+num3<0)question(i,ran);
	    			else
	    			{
	    				ans=num1-num2+num3;
	    		        fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,ans);
	    		        fclose(fp);break;
					}
    			case '-':
    				if(num1-num2-num3<0)question(i,ran);
    				else
    				{
    					ans=num1-num2-num3;
	    		        fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,ans);
	    		        fclose(fp);break;
					}
	    	}
		}
		else
		if(sig1='x')
		{
			switch(sig2)
    		{
	    		case '+':
	    			ans=num1*num2+num3;
	    		    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,ans);
	    		    fclose(fp);break;
    			case '-':
    				if(num1*num2<num3)question(i,ran);
    				else
    				{
    					ans=num1*num2-num3;
	    		        fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,ans);
	    		        fclose(fp);break;
					}
	    	}
		}
	}
	if(num==3)
	{
		if(sig1=='x')
		{
			int ans1;
			ans1=num1*num2;
			if(sig3=='x'&&sig2!='/')
	    	{
		    	int ans2;
		    	ans2=num3*num4;
		    	switch(sig2)
		        {
		        	case '+':
		        		ans=ans1+ans2;
		        	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
		        	    fclose(fp);break;
		        	case '-':
		        		if(ans1>ans2)question(i,ran);
		        		else
		        		{
		        			ans=ans1-ans2;
		        	        fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
		            	    fclose(fp);
					 	}break;
		        	case 'x':
	    	    		ans=ans1*ans2;
		        	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
		         	    fclose(fp);break;
		        }
			}
	      	else
			if(sig3=='/'&&sig2!='/')
	      	{
	      		int ans2,ans3;
	      		count=0;
	      		switch(sig2)
		        {
		        	case '+':
		        		maxn=gcd(num3,num4);
		        		ans2=num3/maxn;
		        		ans3=num4/maxn;
		        		count=0;
		        		while(ans2>ans3)
		        		{
		        			ans2=ans2-ans3;
		        			count++;
						}
						count=count+ans1;
		        	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans2,ans3);
		        	    fclose(fp);break;
		        	case '-':
		        		if(ans1<(num3/num4))question(i,ran);
		        		else
		        		{
		        			maxn=gcd(num3,num4);
		        			ans2=num3/maxn;
		        			ans3=num4/maxn;
		        			count=0;
		        			while(ans2>ans3)
		        			{
		        				ans2=ans2-ans3;
		        				count++;
							}
							count=ans1-count-1;
							ans2=ans3-ans2;
		        	        fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans2,ans3);
		        	        fclose(fp);
						}break;

		        	case 'x':
	    	    		ans1=ans1*num3;
	    	    		maxn=gcd(ans1,num4);
	    	    		count=0;
	    	    		ans2=ans1/maxn;
	    	    		ans3=num4/maxn;
	    	    		while(ans2>ans3)
	    	    		{
	    	    			ans2=ans2-ans3;
	    	    			count++;
						}
		        	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans2,ans3);
		         	    fclose(fp);break;
		        }
			}
			else
			if(sig2=='/')
			{
				count=0;
				int ans2;
				maxn=gcd(ans1,num3);
				ans1=ans1/maxn;
				ans2=num3/maxn;
				while(ans1>ans2)
				{
					ans1=ans1-ans2;
					count++;
				}
				switch(sig3)
				{
					case '+':
						count=count+num4;
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
					    fclose(fp);break;
					case '-':
						if(count<num4)question(i,ran);
						else
						{
							count=count-num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
					        fclose(fp);
						}break;
					case 'x':
						ans1=num1*num2*num4;
						maxn=gcd(ans1,num3);
						count=0;
						ans1=ans1/maxn;
						ans2=num3/maxn;
						while(ans1>ans2)
						{
							ans1=ans1-ans2;
							count++;
						}
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
					    fclose(fp);break;
					case '/':
						ans2=num3*num4;
						maxn=gcd(ans1,ans2);
						count=0;
						ans1=ans1/maxn;
						ans2=ans2/maxn;
						while(ans1>ans2)
						{
							ans1=ans1-ans2;
							count++;
						}
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
						fclose(fp);break;
				}
			}
			else
			if(sig2=='x')
			{
				count=0;
				int ans2,ans;
				ans1=num1*num2*num3;
				switch(sig3)
				{
					case '+':
						ans=ans1+num4;
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
						fclose(fp);break;
					case '-':
						if(ans1<num4)question(i,ran);
						else
						{
							ans=ans1-num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
							fclose(fp);
						}break;
					case 'x':
						ans=ans1*num4;
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
						fclose(fp);break;
					case '/':
						maxn=gcd(ans1,num4);
						ans1=ans1/maxn;
						ans2=num4/maxn;
						while(ans1>ans2)
						{
							ans1=ans1-ans2;
							count++;
						}
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
						fclose(fp);break;
				}
			}
		    else
		    {
		    	int ans2;
		    	switch(sig2)
    	    	{
	        		case '+':
	        			ans2=ans1+num3;break;
        			case '-':
	        			ans2=ans1-num3;break;
	        		case 'x':
        				ans2=ans1*num3;break;
	        	}
			    switch(sig3)
        		{
	        		case '+':
	        			ans=ans2+num4;
	        		    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	        		    fclose(fp);break;
        			case '-':
        				if(ans2<num4)question(i,ran);
        				else
        				{
        					ans=ans2-num4;
	        		        fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	        		        fclose(fp);
						}break;
	        	}
			}
    	}
		else
		if(sig1=='/')
		{
			count=0;
			int ans1,ans2,ans3;
			switch(sig2)
			{
				case '+':
					maxn=gcd(num1,num2);
					ans1=num1/maxn;
					ans2=num2/maxn;
					count=0;
					while(ans1>ans2)
					{
						ans1=ans1-ans2;
						count++;
					}
					switch(sig3)
					{
						case '+':
							ans3=num3+num4;
							count=count+ans3;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	ans3=num3-num4;
	        		    	if(ans<0&&count+ans3<0)question(i,ran);
	        		    	else
	        		    	{
	        		    		count=count+ans3;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans3=num3*num4;
							count=count+ans3;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans1=num1*num4+num3*num2;
	        		    	ans2=num2*num4;
	        		    	maxn=gcd(ans1,ans2);
	        		    	count=0;
	        		    	ans1=ans1/maxn;
	        		    	ans2=ans2/maxn;
	        		    	while(ans1>ans2)
	        		    	{
	        		    		ans1=ans1-ans2;
	        		    		count++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
					}break;
					break;
				case '-':
					maxn=gcd(num1,num2);
					count=0;
					ans1=num1/maxn;
					ans2=num2/maxn;
					while(ans1>ans2)
					{
						ans1=ans1-ans2;
						count++;
					}
					switch(sig3)
					{
						case '+':
							ans3=num3-num4;
							if(count<ans3)question(i,ran);
							else
							{
								count=count-ans3;
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
	        		    case '-':
	        		    	ans3=num3+num4;
	        		    	if(count<ans3)question(i,ran);
	        		    	else
	        		    	{
	        		    		count=count-ans3;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans3=num3*num4;
							if(count<ans3)question(i,ran);
							else
							{
								count=count-ans3;
					    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
						case '/':
	        		    	ans1=num1*num4-num3*num2;
	        		    	ans2=num2*num4;
	        		    	maxn=gcd(ans1,ans2);
	        		    	count=0;
	        		    	ans1=ans1/maxn;
	        		    	ans2=ans2/maxn;
	        		    	while(ans1>ans2)
	        		    	{
	        		    		ans1=ans1-ans2;
	        		    		count++;
							}
							if(ans1<0)question(i,ran);
							else
							{
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
					}break;
				    break;
				case 'x':
					ans1=num1*num3;
					maxn=gcd(ans1,num2);
					ans1=ans1/maxn;
					ans2=num2/maxn;
					while(ans1>ans2)
					{
						ans1=ans1-ans2;
						count++;
					}
					switch(sig3)
					{
						case '+':
							count=count+num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if(count<num4)question(i,ran);
	        		    	else
	        		    	{
	        		    		count=count-num4;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans1=num1*num3*num4;
							maxn=gcd(ans1,num2);
							ans1=ans1/maxn;
							ans2=num2/maxn;
							count=0;
							while(ans1>ans2)
							{
								ans1=ans1-ans2;
								count++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans1=num1*num3;
	        		    	ans2=num2*num4;
	        		    	count=0;
	        		    	maxn=gcd(ans1,ans2);
	        		    	ans1=ans1/maxn;
	        		    	ans2=ans2/maxn;
	        		    	while(ans1>ans2)
							{
								ans1=ans1-ans2;
								count++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
					}break;
				    break;
				case '/':
					ans2=num2*num3;
					maxn=gcd(num1,ans2);
					ans1=num1/maxn;
					ans2=ans2/maxn;
					count=0;
					while(ans1>ans2)
					{
						ans1=ans1-ans2;
						count++;
					}
					switch(sig3)
					{
						case '+':
							count=count+num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if(count<num4)question(i,ran);
	        		    	else
	        		    	{
	        		    		count=count-num4;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans1=num1*num4;
							ans2=num2*num3;
							count=0;
							maxn=gcd(ans1,ans2);
							ans1=ans1/maxn;
							ans2=ans2/maxn;
							while(ans1>ans2)
							{
								ans1=ans1-ans2;
								count++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans1=num1;
	        		    	ans2=num2*num3*num4;
	        		    	count=0;
	        		    	maxn=gcd(num1,ans2);
	        		    	ans1=num1/maxn;
	        		    	ans2=ans2/maxn;
	        		    	while(ans1>ans2)
							{
								ans1=ans1-ans2;
								count++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
					}break;
			        break;
			}
		}
		else
		if(sig2=='x')
		{
			int ans1;
			count=0;
			ans1=num2*num3;
			switch(sig1)
	    	{
		    	int ans2;
		    	case '+':
		    		switch(sig3)
		            {
		            	case '+':
		        	    	ans=num1+ans1+num4;
		            	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
		            	    fclose(fp);break;
		            	case '-':
		            		if(num1+ans1<num4)question(i,ran);
		            		else
		            		{
		            			ans=num1+ans1-num4;
		            			fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
		                	    fclose(fp);
							}break;
		             	case 'x':
	    	    	    	ans=num1+num4*ans1;
		            	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
		             	    fclose(fp);break;
		        	    case '/':
		            		maxn=gcd(ans1,num4);
		            		count=0;
		            		ans1=ans1/maxn;
		            		ans2=num4/maxn;
		            		while(ans1>ans2)
		            		{
		            			ans1=ans1-ans2;
		            			count++;
							}
							count=count+num1;
		        	        fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	 	        	        fclose(fp);break;
		            }break;
		            break;
				case '-':
		        	switch(sig3)
		            {
		            	case '+':
		            		if(maxn+num4<ans1)question(i,ran);
		            		else
		            		{
		            			ans=num1-ans1+num4;
		            			fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
		            	        fclose(fp);
							}break;
		            	case '-':
		            		if(num1<ans1+num4)question(i,ran);
		            		else
		            		{
		            			ans=num1-ans1-num4;
		            			fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
		                	    fclose(fp);
							}break;
		             	case 'x':
		             		if(num1<ans1*num4)question(i,ran);
		             		else
		             		{
		             			ans=num1-num4*ans1;
		             			fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
		             	        fclose(fp);
							}break;
		        	    case '/':
		            		maxn=gcd(ans1,num4);
		            		count=0;
		            		ans1=ans1/maxn;
		            		ans2=num4/maxn;
		            		while(ans1>ans2)
		            		{
		            			ans1=ans1-ans2;
		            			count++;
							}
							if(num1<=count)question(i,ran);
							else
							{
								count=num1-count-1;
								ans1=ans2-ans1;
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	 	        	            fclose(fp);
							}break;
		            }break;
			    break;
			}
		}
		else
		if(sig2=='/')
		{
			int ans1,ans2;
			count=0;
			maxn=gcd(num2,num3);
			ans1=num2/maxn;
			ans2=num3/maxn;
			while(ans1>ans2)
			{
				ans1=ans1-ans2;
				count++;
			}
			switch(sig1)
			{
				case'+':
					switch(sig3)
					{
						case '+':
							count=count+num1+num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if(num1+count<num4)question(i,ran);
	        		    	else
	        		    	{
	        		    		count=count+num1-num4;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);break;
							}
						case 'x':
							ans1=num2*num4;
							count=0;
							maxn=gcd(ans1,num3);
							ans1=ans1/maxn;
							ans2=ans2/maxn;
							while(ans1>ans2)
							{
								ans1=ans1-ans2;
								count++;
							}
							count=count+num1;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans2=num3*num4;
	        		    	count=0;
	        		    	maxn=gcd(num2,ans2);
	        		    	ans1=num2/maxn;
	        		    	ans2=ans2/maxn;
	        		    	while(ans1>ans2)
							{
								ans1=ans1-ans2;
								count++;
							}
							count=count+num1;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
					}break;
			        break;
				case '-':
					switch(sig3)
					{
						case '+':
							if(num1+num4<count)question(i,ran);
							else
							{
								count=num1+num4-count-1;
								ans1=ans2-ans1;
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
	        		    case '-':
	        		    	if(num1<num4+count)question(i,ran);
	        		    	else
	        		    	{
	        		    		count=num1-num4-count-1;
	        		    		ans1=ans2-ans1;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans1=num2*num4;
							count=0;
							maxn=gcd(ans1,num3);
							ans1=ans1/maxn;
							ans2=ans2/maxn;
							while(ans1>ans2)
							{
								ans1=ans1-ans2;
								count++;
							}
							count=num1-count-1;
							ans1=ans2-ans1;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans2=num3*num4;
	        		    	count=0;
	        		    	maxn=gcd(num2,ans2);
	        		    	ans1=num2/maxn;
	        		    	ans2=ans2/maxn;
	        		    	while(ans1>ans2)
							{
								ans1=ans1-ans2;
								count++;
							}
							count=num1-count-1;
							ans1=ans2-ans1;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
					}break;
		            break;
			}
		}
		else
		if(sig3=='x')
		{
			int ans1;
			ans1=num3*num4;
			int ans2;
		    switch(sig1)
    	    {
	        	case '+':
	        		ans2=num1+num2;break;
        		case '-':
	        		ans2=num1-num2;break;
	        }
			switch(sig2)
        	{
	        	case '+':
	        		ans=ans1+ans2;
	        		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	        		fclose(fp);break;
        		case '-':
        			if(ans1<ans2)question(i,ran);
        			else
        			{
        				ans=ans1-ans2;
        				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	        	        fclose(fp);
					}break;
	        }
		}
		else
		if(sig3=='/')
		{
			count=0;
			int ans1,ans2;
			maxn=gcd(num3,num4);
			ans1=num3/maxn;
			ans2=num4/maxn;
			while(ans1>ans2)
			{
				ans1=ans1-ans2;
				count++;
			}
			switch(sig1)
			{
				case '+':
					switch(sig2)
					{
						case '+':
							count=count+num1+num2;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if(num1+num2<count)question(i,ran);
	        		    	else
	        		    	{
	        		    		count=num1+num2-count-1;
	        		    		ans1=ans2-ans1;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
					}break;
				case '-':
					switch(sig2)
					{
						case '+':
							if(num1+count<num2)question(i,ran);
							else
							{
								count=num1+count-num2;
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
	        		    case '-':
	        		    	if(num1<count+num2)question(i,ran);
	        		    	else
	        		    	{
	        		    		count=num1-num2-count-1;
	        		    		ans1=ans2-ans1;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,count,ans1,ans2);
	        		            fclose(fp);
							}break;
					}break;
			}
		}
	    else
	    if(sig1=='+')
	    {
	    	int ans1,ans2,ans;
	    	ans1=num1+num2;
	    	if(sig2=='+')
	    	{
	    		ans2=ans1+num3;
	    		if(sig3=='+')
	    		{
	    			ans=ans2+num4;
	    			fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	    			fclose(fp);
				}
				else
				if(sig3=='-')
	    		{
	    			if(ans2<num4)question(i,ran);
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	    				fclose(fp);
					}
				}
	    	}
	    	else
			if(sig2=='-')
			{
				ans2=ans1-num3;
				if(sig3=='+')
	    		{
	    			if(ans2+num4<0)question(i,ran);
	    			else
	    			{
	    				ans=ans2+num4;
	    		    	fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	    		    	fclose(fp);
					}
				}
				else
				if(sig3=='-')
	    		{
	    			if(ans2-num4<0)question(i,ran);
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	    				fclose(fp);
					}
				}
			}
    	}
    	else
	    if(sig1=='-')
	    {
	    	int ans1,ans2,ans;
	    	ans1=num1-num2;
	    	if(sig2=='+')
	    	{
	    		ans2=ans1+num3;
	    		if(sig3=='+')
	    		{
	    			if(ans2+num4<0)question(i,ran);
	    			else
	    			{
	    				ans=ans2+num4;
	    		    	fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	    		    	fclose(fp);
					}
				}
				else
				if(sig3=='-')
	    		{
	    			if(ans2<num4)question(i,ran);
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	    				fclose(fp);
					}
				}
	    	}
	    	else
			if(sig2=='-')
			{
				ans2=ans1-num3;
				if(sig3=='+')
	    		{
	    			if(ans2+num4<0)question(i,ran);
	    			else
	    			{
	    				ans=ans2+num4;
	    		    	fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	    		    	fclose(fp);
					}
				}
				else
				if(sig3=='-')
	    		{
	    			if(ans2-num4<0)question(i,ran);
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",i,num1,sig1,num2,sig2,num3,sig3,num4,ans);
	    				fclose(fp);
					}
				}
			}
    	}

	}
	return 0;
}
int question(int i,int ran)//生成题目
{
	FILE *fp;
    int get;
    int num,num1,num2,num3,num4;//运算数
    char sig1,sig2,sig3;//符号

    sig1=getSig();
    sig2=getSig();
    sig3=getSig();
    num1=random(ran);
    num2=random(ran);
    num3=random(ran);
    num4=random(ran);
    num=rand()%3+1;

    if(num==1)
    {
     	answers(i,num,num1,num2,num3,num4,sig1,sig2,sig3,ran);
     	fp=fopen("Exercises.txt","a+");
     	fprintf(fp,"题目%d:%d %c %d = \n",i,num1,sig1,num2);
     	fclose(fp);
	}
	if(num==2)
	{
     	answers(i,num,num1,num2,num3,num4,sig1,sig2,sig3,ran);
     	fp=fopen("Exercises.txt","a+");
     	fprintf(fp,"题目%d:%d %c %d %c %d = \n",i,num1,sig1,num2,sig2,num3);
     	fclose(fp);
    }
	if(num==3)
	{
     	answers(i,num,num1,num2,num3,num4,sig1,sig2,sig3,ran);
     	fp=fopen("Exercises.txt","a+");
     	fprintf(fp,"题目%d:%d %c %d %c %d %c %d = \n",i,num1,sig1,num2,sig2,num3,sig3,num4);
     	fclose(fp);
	}
	return 0;
}

int match_results(){

    char exer[N];
    char ans[N];
    int i=0,correct=0,wrong=0;
    FILE * fp1 = NULL;
    FILE * fp2 = NULL;
    FILE * fp3 = NULL;

    fp1 = fopen("Exercises.txt","r");
    fp2 = fopen("Answers.txt","r");
    fp3 = fopen("Score.txt","a+");

    if( (fp1 == NULL)|| (fp2 == NULL) ){
        puts("ERROR WITH DOCUMENT!!!");
        exit(0);
    }

    while((fgets(exer, N, fp1) != NULL)||(fgets(ans, N, fp2) != NULL)){
        if(!strcmp(exer,ans)){
            correct++;
          }
          else{
            wrong++;
          }
    }
    fclose(fp1);
    fclose(fp2);
    fprintf(fp3,"correct:%d, wrong:%d",correct,wrong);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
int main()
{
	srand((unsigned)time(0));
	int num,ran,ch;// number,range,choice
	int i=1;
	char argv1[3];
    char argv2[3];
    char argv3[3];
    char Ei;// endinput

    printf("请选择功能：生成题目请输入1，生成成绩请输入2\n");
    scanf("%d",&ch);
    scanf("%c",&Ei);
    switch (ch){
        case 1:
            printf("请输入题目数量（-n），与题目范围（-r）\n");
            scanf("%s",argv1);//-n
            scanf("%d",&num);
            scanf("%s",argv2);//-r
            scanf("%d",&ran);
            if(!strcmp(argv1,"-n")&&!strcmp(argv2,"-r"))
            {
                while(num>0)
                {
                    question(i,ran);
                    i++;
                    num--;
                }
            }
            else
                printf("输入错误！");
            break;

        case 2:
            printf("请输入答案匹配功能（-g）\n");
            scanf("%s",argv3);//-g
            if(!strcmp(argv3,"-g"))
                match_results();
            else
                printf("输入错误！");
            break;
    }
    return 0;
}
