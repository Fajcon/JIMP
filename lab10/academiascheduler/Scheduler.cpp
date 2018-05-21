//
// Created by fajcon on 21.05.18.
//

#include "Scheduler.h"

namespace academia{


    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year)
        : course_id_(course_id), teacher_id_(teacher_id), room_id_(room_id), time_slot_(time_slot), year_(year){

    }

    int SchedulingItem::CourseId() const {
        return course_id_;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId() const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule result;
        std::copy_if(data_.begin(), data_.end(), std::back_inserter(result.data_),
                     [teacher_id](const SchedulingItem &p)
                     { return teacher_id==p.TeacherId();});
        return result;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule result;
        std::copy_if(data_.begin(), data_.end(), std::back_inserter(result.data_),
                     [room_id](const SchedulingItem &p)
                     { return room_id==p.RoomId();});
        return result;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule result;
        std::copy_if(data_.begin(), data_.end(), std::back_inserter(result.data_),
                     [year](const SchedulingItem &p)
                     { return year==p.Year();});
        return result;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        bool used[n_time_slots];
        for (int i=0; i<n_time_slots; ++i){
            used[i]= false;
        }
        for (const SchedulingItem& it:data_){
            used[it.TimeSlot()-1]= true;
        }
        std::vector<int> result;
        for(int i=0; i<n_time_slots; ++i){
            if (!used[i])
                result.emplace_back(i+1);
        }
        return result;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        data_.emplace_back(item);
    }

    size_t Schedule::Size() const {
        return data_.size();
    }

    SchedulingItem Schedule::operator[](size_t index) const {
        return data_[index];
    }

    NoViableSolutionFound::NoViableSolutionFound() {
        message_="";
    }

    const char *NoViableSolutionFound::what() {
        return message_.c_str();
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule schedule;
        for (const auto &single_teacher:teacher_courses_assignment){
            for(int course:single_teacher.second){
                int year = this->FindYearWithCourse(courses_of_year, course);
                std::pair<int, int> room_and_time = FindRoomAndSlot(schedule, single_teacher.first, rooms, n_time_slots, year);
                schedule.InsertScheduleItem(SchedulingItem(course, single_teacher.first, room_and_time.first,
                                                           room_and_time.second, year));
            }
        }
        return schedule;
    }

    std::pair<int, int>GreedyScheduler::FindRoomAndSlot(const Schedule &schedule, int teacher, const std::vector<int> &rooms,
                                     int n_time_slots, int year) const {
        std::vector<int> teacher_free_slots;
        teacher_free_slots = schedule.OfTeacher(teacher).AvailableTimeSlots(n_time_slots);
        std::vector<int> year_free_slots;
        year_free_slots = schedule.OfYear(year).AvailableTimeSlots(n_time_slots);
        std::vector<int> both_free_slots;
        std::set_intersection(teacher_free_slots.begin(), teacher_free_slots.end(),
                              year_free_slots.begin(), year_free_slots.end(),
                              std::back_inserter(both_free_slots));

        for (int room:rooms) {
            std::vector<int> room_free_slots;
            room_free_slots = schedule.OfRoom(room).AvailableTimeSlots(n_time_slots);

            std::vector<int> all_free_slots;
            std::set_intersection(both_free_slots.begin(), both_free_slots.end(),
                                  room_free_slots.begin(), room_free_slots.end(),
                                  std::back_inserter(all_free_slots));
            if(!all_free_slots.empty()){
                return std::make_pair(room, all_free_slots[0]);
            }
        }
        throw NoViableSolutionFound();
    }

    int GreedyScheduler::FindYearWithCourse(const std::map<int, std::set<int>> &courses_of_year, int course) {
        for(const auto& single_year_courses:courses_of_year){
            if (std::count(single_year_courses.second.begin(), single_year_courses.second.end(), course)){
                return single_year_courses.first;
            }
        }
        throw NoViableSolutionFound();
    }
}