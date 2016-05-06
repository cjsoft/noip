# coding=utf-8
import smtplib
from email.mime.text import MIMEText
from email.header import Header
from pw import password
sender = 'egwcyh@qq.com'
receiver = 'egwcyh@qq.com'
subject = 'python email test'
smtpserver = 'smtp.qq.com'
username = 'egwcyh@qq.com'

msg = MIMEText('你好sd','plain','utf-8')#中文需参数‘utf-8’，单字节字符不需要
msg['Subject'] = Header(subject, 'utf-8')

smtp = smtplib.SMTP()
smtp.connect('smtp.qq.com')
smtp.login(username, password)
smtp.sendmail(sender, receiver, msg.as_string())
smtp.quit()