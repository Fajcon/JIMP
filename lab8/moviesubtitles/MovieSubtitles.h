//
// Created by ficon on 03.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <regex>

namespace moviesubs {
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                 std::istream *in, std::ostream *out) = 0;
    };



    class MicroDvdSubtitles : public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                         std::istream *in, std::ostream *out) override;

    };

    class SubtitlesException : public std::exception{
    public:
        //SubtitlesException(int line_index, const std::string line);
        const char* what () const noexcept override;
        std::string message_;
        std::string line_;
        int line_number_;
    };

    class NegativeFrameAfterShift :public SubtitlesException{

    };

    class SubtitleEndBeforeStart :public SubtitlesException{
    public:
        SubtitleEndBeforeStart(int line_index, const std::string line);
        int LineAt() const;

    };

    class InvalidSubtitleLineFormat :public SubtitlesException{

    };

    class OutOfOrderFrames : public  SubtitlesException{

    };

    class MissingTimeSpecification : public SubtitlesException{

    };

    class SubRipSubtitles : public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                 std::istream *in, std::ostream *out) override;
    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
