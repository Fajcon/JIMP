//
// Created by ficon on 03.05.18.
//

#include "MovieSubtitles.h"
namespace moviesubs {

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds,
                                                int frame_per_second, std::istream *in,
                                                std::ostream *out) {
        if (frame_per_second < 0){
            throw std::invalid_argument("error");
        }

        int shift=(offset_in_micro_seconds*frame_per_second)/1000;

        std::regex regex_pattern(R"(\{(-?\d+)\}\{(-?\d+)\}(.+))");
        int line_index=1;
        char line_buffer[1000];
        int test_frame = 0;
        while(in->getline(line_buffer, 1000)) {
            std::cmatch sub;
            if (std::regex_match(line_buffer, sub, regex_pattern)){
                int start_frame = std::stoi(sub[1])+shift;
                int end_frame = std::stoi(sub[2])+shift;
                if (start_frame < 0){
                    throw(NegativeFrameAfterShift());
                }
                if (start_frame>end_frame){
                    throw(SubtitleEndBeforeStart(line_index, sub[0]));
                }
                if(test_frame > start_frame){
                    throw(OutOfOrderFrames());
                }
                int test_frame = end_frame;

                (*out)<<"{"<<start_frame<<"}{"<<end_frame<<"}"<<sub[3]<<"\n";

                }else{
                throw(InvalidSubtitleLineFormat());
            }
            ++line_index;
            }
    }

    int SubtitleEndBeforeStart::LineAt() const {
        return line_number_;;
    }

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_index, const std::string line){
        std::stringstream out_stream;
        line_ = line;
        line_number_=line_index;
        out_stream<<"At line "<<line_number_<<": "<<line;
        message_=out_stream.str();

    }

    /*SubtitlesException::SubtitlesException(int line_index, std::string line) {
        std::stringstream out_stream;
        line_ = line;
        line_number_=line_index;
        out_stream<<"At line "<<line_number_<<": "<<line;
        message_=out_stream.str();
    }*/

    const char *SubtitlesException::what() const noexcept {
        return message_.c_str();
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds,
                                              int frame_per_second, std::istream *in,
                                              std::ostream *out) {
        if (frame_per_second < 0){
            throw std::invalid_argument("error");
        }
        std::regex regex_pattern(R"((\d\d):(\d\d):(\d\d),(\d\d\d) --> (\d\d):(\d\d):(\d\d),(\d\d\d))");
        std::regex index_pattern(R"((\d+))");
        int line_index=1;
        int index = 1;
        char line_buffer[1000];


        while(in->getline(line_buffer, 1000)) {
            std::cmatch sub;
            std::cmatch sub2;
            if(index > 2 && line_index == 1){
                throw InvalidSubtitleLineFormat();
            }
            if (std::regex_match(line_buffer, sub2, index_pattern)){
                int test = std::stoi(sub2[1]);
                if (test != line_index) throw OutOfOrderFrames();
            }
            if (std::regex_match(line_buffer, sub, regex_pattern)){

                if (offset_in_micro_seconds*(-1) > std::stoi(sub[4])+std::stoi(sub[3])*1000){
                    throw(NegativeFrameAfterShift());
                }

                int micro_seconds = std::stoi(sub[4])+offset_in_micro_seconds;

                int seconds = std::stoi(sub[3]);
                if(micro_seconds > 999){
                    micro_seconds -= 1000;
                    seconds = std::stoi(sub[3])+1;
                }

                int minutes = std::stoi(sub[2]);
                int hours = std::stoi(sub[1]);


                int micro_seconds2 = std::stoi(sub[8])+offset_in_micro_seconds;
                int seconds2 = std::stoi(sub[7]);
                if(micro_seconds2 > 999){
                    micro_seconds2 -= 1000;
                    seconds2 = std::stoi(sub[7])+1;
                }
                int minutes2 = std::stoi(sub[6]);
                int hours2 = std::stoi(sub[5]);

                int time = hours+60*60*1000+minutes*60*1000+seconds*1000+micro_seconds;
                int time2 = hours2+60*60*1000+minutes2*60*1000+seconds2*1000+micro_seconds2;


                if(time2<time){
                    throw(SubtitleEndBeforeStart(line_index, sub[0]));
                }

                if(hours<10)(*out)<<"0"<<hours<<":";
                else (*out)<<hours<<":";
                if(minutes<10)(*out)<<"0"<<minutes<<":";
                else (*out)<<minutes<<":";
                if(seconds<10)(*out)<<"0"<<seconds<<",";
                else (*out)<<seconds<<",";
                (*out)<<micro_seconds<<" --> ";
                if(hours2<10)(*out)<<"0"<<hours2<<":";
                else (*out)<<hours2<<":";
                if(minutes2<10)(*out)<<"0"<<minutes2<<":";
                else (*out)<<minutes2<<":";
                if(seconds2<10)(*out)<<"0"<<seconds2<<",";
                else (*out)<<seconds2<<",";
                if(micro_seconds2 < 100)(*out)<<"0"<<micro_seconds2<<"\n";
                else(*out)<<micro_seconds2<<"\n";
                line_index++;


            }else{
                (*out) << line_buffer << "\n";
            }
            index++;
            }

        }


}