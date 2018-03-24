

//
// Created by fajcon on 21.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <algorithm>
#include <string>
#include <unordered_map>



namespace nets {
    class View {

    public:
        View(std::string text1);
        ~View();
        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    private:
        std::string text_;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
