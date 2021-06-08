def work(word):
    x=1
    if(word[0].isdigit()):
        i=1
        x=int(word[0])
    else:
        i=0
    d={}
    s=''
    word+=' '
    for i in range(i,len(word)):
        if(word[i].isdigit()):
            d[s]=d.get(s,0)+int(word[i])
            s=''   
        elif(word[i].islower()):
            s+=word[i]
        elif(word[i].isupper()):
            if(s):
                d[s]=d.get(s,0)+1
            s=word[i]
        elif(word[i]==' '):
            if(s!=''):d[s]=d.get(s,0)+1
       
    for key in d.keys():
        d[key]*=x
    return d
n=int(input())
for i in range(n):
    s=input().strip()
    left,right=s.split('=')
    left=left.split('+')
    right=right.split('+')
    left_ans={}
    right_ans={}
    for word in left:
        ans=work(word)
        for key in ans.keys():
            left_ans[key]=left_ans.get(key,0)+ans[key]
    for word in right:
        ans=work(word)
        for key in ans.keys():
            right_ans[key]=right_ans.get(key,0)+ans[key]
    if(left_ans==right_ans):
        print("Y")
    else:
        print("N")