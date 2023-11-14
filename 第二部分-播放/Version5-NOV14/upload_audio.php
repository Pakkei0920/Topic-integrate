<?php
if ($_SERVER["REQUEST_METHOD"] === "POST" && $_SERVER["CONTENT_TYPE"] === "audio/wav") {
    // 生成文件名
    $filepath = "audio_file/" . date('Ymd_his_') . "esp32rec.wav";
    $flacpath = "flac_file/" . date('Ymd_his_') . "esp32rec.flac";
    // 将接收到的音频数据保存到文件
    $fileContent = file_get_contents("php://input");
    file_put_contents($filepath, $fileContent);
    echo "音频文件已成功保存到：$filepath";
    
//***//
shell_exec("ffmpeg -i $filepath -c:a flac $flacpath");
//***//

$request_data = [
    'config' => [
        'encoding' => 'flac',
        'sampleRateHertz' => 16000, // 根据您的音频文件配置
        'languageCode' => 'zh-tw', // 选择目标语言
    ],
    'audio' => [
        'content' => base64_encode(file_get_contents($flacpath)),
    ],
];

// 构建请求
$ch = curl_init("https://speech.googleapis.com/v1/speech:recognize?key=AIzaSyDokQSVT6kakHhFIo4sKBWkJbzgqpn22bM");
curl_setopt_array($ch, [
    CURLOPT_CUSTOMREQUEST => 'POST',
    CURLOPT_POSTFIELDS => json_encode($request_data),
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_HTTPHEADER => [
        'Content-Type: application/json',
    ],
]);
// 发送请求并解析响应
$response = json_decode(curl_exec($ch), true);
// 显示识别结果或无法识别音频
$result = isset($response['results'][0]['alternatives'][0]['transcript'])
    ? $response['results'][0]['alternatives'][0]['transcript']
    : '无法识别音频';
curl_close($ch);

//***//
    
 //Line API
$channelAccessToken = 'RYx398mxwhtxFlsC6DT7bQBFn3iSDYlr+Qtrdcz4IYnq0Wj1/4vdyuuAcOOiSMEUroDLhPw9kVk4wYXAt8yP6hcHPUqy3r/eRXFB1/4IRPZ4gR2OenZ84CdKMgdo7i7YYXv//5EEG4lWg+lNkeCP1AdB04t89/1O/w1cDnyilFU=';
$data = [
    'to' => "U2059804cf115fe02c13b4b87d1e12a68",
    'messages' => [
        [
            'type' => 'text',
            'text' => $result, 
        ],
        [
            'type' => 'audio',
            'originalContentUrl' => 'https://topics.paki91.com/ETL/'.$filepath,
            'duration' => 15000,
        ],
    ],
];

$postData = json_encode($data);
$headers = [
    'Content-Type: application/json',
    'Authorization: Bearer ' . $channelAccessToken,
];

$ch = curl_init('https://api.line.me/v2/bot/message/push');
curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'POST');
curl_setopt($ch, CURLOPT_POSTFIELDS, $postData);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
$result = curl_exec($ch);
curl_close($ch);

echo $result;
}
?>
