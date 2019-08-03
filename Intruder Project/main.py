import  json, time, requests
from boltiot import Sms, Bolt
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

email = 'aduhenewisdom97@gmail.com '
password = '0547351485w'
send_to_email = ' wisdom.nkoah@stu.ucc.edu.gh'
subject = 'intrusion'
message = 'Someone Entered !!'

msg = MIMEMultipart()
msg['From'] = email
msg['To'] = send_to_email
msg['Subject'] = subject

msg.attach(MIMEText(message, 'plain'))

SID="AC3dc07f4892699d6a66f66fc4afb28a8f"
AUTH_TOKEN="••••••••••••••••••••••••••••••••"
FROM_NUMBER="0547351485"
TO_NUMBER="0245057898"

sms = Sms(SID, AUTH_TOKEN, TO_NUMBER, FROM_NUMBER)

while True:
    response = requests.get('http://cloud.boltiot.com/remote/e0f2449f-c1b0-483c-8bd8-f4ba5fc32a89/digitalRead?pin=0&deviceName=BOLT6094123')
    data=json.loads(response.text)
    print(data)
    sensor_value = int(data['value'])
    if sensor_value == 1:
        print("MOTION DETECTED")
        print("sending SMS")
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        server.login(email, password)
        text = msg.as_string()
        server.sendmail(email, send_to_email, text)
        sms.send_sms("SOMEONE ENTERED")
        server.quit()
    elif sensor_value ==0:
        print("SENSOR IS READY")
    time.sleep(5)