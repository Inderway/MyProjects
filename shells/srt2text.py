# -*- coding=utf8 -*-
# Aug 24, 2025
# 将srt字幕文件转为连续的文本
# Coded by Grok, modified by AtoZ

def extract_srt_subtitles(file_path):
    try:
        # 打开并读取 SRT 文件（假设文件使用 UTF-8 编码）
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = file.readlines()
        
        # 用于存储字幕内容的列表
        subtitles = []
        # 每四行一组，提取第三行的字幕内容
        for i in range(0, len(lines), 4):
            # 确保第三行存在且不为空
            if i + 2 < len(lines):
                subtitle_line = lines[i + 2].strip()
                if subtitle_line:  # 仅添加非空内容
                    subtitles.append(subtitle_line)
                    if i%120 == 0:
                        subtitles.append("\n\n")
        
        # 使用逗号连接所有字幕内容
        result = ','.join(subtitles)
        return result
    
    except FileNotFoundError:
        return "错误：找不到指定的 SRT 文件！"
    except UnicodeDecodeError:
        return "错误：文件编码不支持，请确保文件为 UTF-8 编码！"
    except Exception as e:
        return f"错误：{str(e)}"

# 示例使用
if __name__ == "__main__":
    # 替换为你的 SRT 文件路径
    srt_filepath = r"D:\documents\考公\申论-单淑玲"
    srt_filename = "方法精讲-申论7-单淑玲"
    result = extract_srt_subtitles(f"{srt_filepath}\\{srt_filename}.srt")
    with open(f"{srt_filepath}\\{srt_filename}.txt","w",encoding='utf-8') as file:
        file.write(result)