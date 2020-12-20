# coding: gbk
import json
from pymediainfo import MediaInfo
from pprint import pprint
import os



def songRename():
    dir_path = 'C:\\Users\\hp\\Music\\音乐\\Falcom\\'
    for file in os.listdir(dir_path):
        #print(dir_path + file)
        #用.分隔字符串至多1次，取结果（类型为list）的第二个
        format=file.split('.',1)[1]
        #print(format)
        if format!='mp3' and format!='flac':
            continue
        media_info = MediaInfo.parse(dir_path + file)
        media_data = json.loads(media_info.to_json())['tracks'][0]
        #pprint(media_data)
        file_name=media_data['complete_name']
        name = str(media_data['file_name']+'.'+media_data['file_extension'])
        song_name = media_data['title']+'.'+media_data['file_extension']
        #格式化输出
        if name != song_name:
            print(file)
            print('-%s <<<>>> %s' %(name,song_name))
            print('---'+dir_path+song_name)

            try:
                direction = dir_path + song_name
                direction.encode('gbk')
                os.rename(file_name,direction)

            except:
                continue

    # for track in media_info.tracks:
    #     if track.track_type == "Video":
    #         print("Bit rate: {t.bit_rate}, Frame rate: {t.frame_rate}, "
    #               "Format: {t.format}".format(t=track)
    #               )
    #         print("Duration (raw value):", track.duration)
    #         print("Duration (other values:")
    #         pprint(track.other_duration)
    #     elif track.track_type == "Audio":
    #         print("Track data:")
    #         pprint(track.to_data())


if __name__ == '__main__':
    songRename()
