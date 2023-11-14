<?php
if ($_SERVER["REQUEST_METHOD"] === "POST" && $_SERVER["CONTENT_TYPE"] === "audio/wav") {
    // 生成文件名
    $filepath = "audio_file/" . date('Ymd_his_') . "esp32rec.wav";

    // 将接收到的音频数据保存到文件
    $fileContent = file_get_contents("php://input");
    file_put_contents($filepath, $fileContent);
    
    echo "音频文件已成功保存到：$filepath";


 //Line API
$channelAccessToken = 'RYx398mxwhtxFlsC6DT7bQBFn3iSDYlr+Qtrdcz4IYnq0Wj1/4vdyuuAcOOiSMEUroDLhPw9kVk4wYXAt8yP6hcHPUqy3r/eRXFB1/4IRPZ4gR2OenZ84CdKMgdo7i7YYXv//5EEG4lWg+lNkeCP1AdB04t89/1O/w1cDnyilFU=';

// 创建消息数组
$data = [
    'to' => 'U2059804cf115fe02c13b4b87d1e12a68', // 将USER_ID替换为接收消息的用户ID
    'messages' => [
        [
            'type' => 'audio', // 指定消息类型为语音
            'originalContentUrl' => 'https://topics.paki91.com/ETL/'.$filepath, // 替换为您的语音文件URL
            'duration' => 15000 // 语音持续时间（以毫秒为单位）
        ]
    ]
];

// 将消息数据转换为JSON格式
$postData = json_encode($data);

// 设置HTTP请求头
$headers = [
    'Content-Type: application/json',
    'Authorization: Bearer ' . $channelAccessToken
];

// 使用cURL发送POST请求
$ch = curl_init('https://api.line.me/v2/bot/message/push');
curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'POST');
curl_setopt($ch, CURLOPT_POSTFIELDS, $postData);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
$result = curl_exec($ch);
curl_close($ch);

// 打印API响应
echo $result;
      
}
else {
        header('HTTP/1.0 404 Not Found');
    }

?>
