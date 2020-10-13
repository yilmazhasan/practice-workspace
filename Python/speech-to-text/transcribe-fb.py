import speech_recognition as sr
from enum import Enum, unique

# ref: https://www.slanglabs.in/blog/automatic-speech-recognition-in-python-programs

TESTCASES = [
    {
    'filename': 'C://Users//hasany//Downloads//heyThere.flac',
    'text': 'Hey There',
    'encoding': 'LINEAR16',
    'lang': 'en-US'
  }
#   ,
#   {
#     'filename': 'C://Users//hasany//Downloads//Recording-2.flac',
#     'text': 'Şiir',
#     'encoding': 'LINEAR16',
#     'lang': 'tr-TR'
#   }
]

def write_to_file(file_path, content):
    f = open(file_path, "a", encoding='utf-8')
    f.write(content)
    f.close()


@unique
class ASREngine(Enum):
    # sphinx = 0
    google = 1

def speech_to_text(filename: str, engine: ASREngine, language: str, show_all: bool = False) -> str:
    r = sr.Recognizer()

    with sr.AudioFile(filename) as source:
        audio = r.record(source)

    asr_functions = {
        # ASREngine.sphinx: r.recognize_sphinx,
        ASREngine.google: r.recognize_google,
    }

    response = asr_functions[engine](audio, language=language, show_all=show_all)
    return response

# Run tests
for t in TESTCASES:
    filename = t['filename']
    text = t['text']
    lang = t['lang']

    print('\naudio file="{0}"    expected text="{1}"'.format(
        filename, text
    ))
    i = 1
    for asr_engine in ASREngine:
        try:
            response = speech_to_text(filename, asr_engine, language=lang)
            print('{0}: "{1}"'.format(asr_engine.name, response))
            write_to_file('output_{0}.txt'.format(str(i)), response)
        except sr.UnknownValueError:
            print('{0} could not understand audio'.format(
                asr_engine.name
            ))
        except sr.RequestError as e:
            print('{0} error: {0}'.format(asr_engine.name, e))