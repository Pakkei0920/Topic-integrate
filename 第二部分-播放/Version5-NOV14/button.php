<?php
$data = $_POST['data'];

if ($data == '1') {
    // ����邮ogs.txt���辣撟嗅�坔�交㺭�旿
    $logFile = fopen("button_logs.txt", "a");
    
    if ($logFile) {
        fwrite($logFile, "Button pressed - " . date("Y-m-d H:i:s") . "\n");
        fclose($logFile);
        echo "Button pressed data received and logged.";
        
        
$channelAccessToken = 'RYx398mxwhtxFlsC6DT7bQBFn3iSDYlr+Qtrdcz4IYnq0Wj1/4vdyuuAcOOiSMEUroDLhPw9kVk4wYXAt8yP6hcHPUqy3r/eRXFB1/4IRPZ4gR2OenZ84CdKMgdo7i7YYXv//5EEG4lWg+lNkeCP1AdB04t89/1O/w1cDnyilFU='; // 請替換成您的Channel Access Token
$userId = 'U2059804cf115fe02c13b4b87d1e12a68'; // 請替換成您的目標用戶ID

$url = 'https://api.line.me/v2/bot/message/push';

$headers = array(
    'Content-Type: application/json',
    'Authorization: Bearer ' . $channelAccessToken
);

$data = '{
    "to": "' . $userId . '",
    "messages": [
        {
            "type": "flex",
            "altText": "危險警報",
            "contents": {
                "type": "bubble",
                "hero": {
                    "type": "image",
                    "url": "https://media.istockphoto.com/id/1152189152/zh/%E5%90%91%E9%87%8F/%E7%B4%85%E8%89%B2%E8%AD%A6%E5%A0%B1%E5%9C%96%E7%A4%BA.jpg?s=612x612&w=0&k=20&c=rIUsKlq6wTH2W1lwKF7DBDJDayTdzZkDgQltUOeiCHI=",
                    "size": "full",
                    "aspectRatio": "20:13",
                    "aspectMode": "cover",
                    "action": {
                        "type": "uri",
                        "uri": "http://linecorp.com/"
                    }
                },
                "body": {
                    "type": "box",
                    "layout": "vertical",
                    "contents": [
                        {
                            "type": "text",
                            "text": "危險！危險！危險！",
                            "weight": "bold",
                            "size": "xl",
                            "color": "#ff0000"
                        },
                        {
                            "type": "box",
                            "layout": "vertical",
                            "margin": "lg",
                            "spacing": "sm",
                            "contents": [
                                {
                                    "type": "box",
                                    "layout": "baseline",
                                    "spacing": "sm",
                                    "contents": [
                                        {
                                            "type": "text",
                                            "text": "請立刻、馬上關注家庭老人狀況",
                                            "wrap": true,
                                            "color": "#000000",
                                            "size": "md",
                                            "flex": 99
                                        }
                                    ]
                                }
                            ]
                        }
                    ]
                },
                "footer": {
                    "type": "box",
                    "layout": "vertical",
                    "spacing": "sm",
                    "contents": [
                        {
                            "type": "button",
                            "style": "link",
                            "height": "sm",
                            "action": {
                                "type": "uri",
                                "label": "緊急電話",
                                "uri": "https://topics.paki91.com/call.php"
                            }
                        },
                        {
                            "type": "button",
                            "style": "link",
                            "height": "sm",
                            "action": {
                                "type": "uri",
                                "label": "日誌記錄",
                                "uri": "https://topics.paki91.com/ETL/button_logs.txt"
                            }
                        }
                    ],
                    "flex": 0
                }
            }
        }
    ]
}';

$ch = curl_init($url);
curl_setopt($ch, CURLOPT_POST, 1);
curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

$response = curl_exec($ch);

if (curl_errno($ch)) {
    echo 'Error:' . curl_error($ch);
}

curl_close($ch);

echo $response;
    }}
?>
