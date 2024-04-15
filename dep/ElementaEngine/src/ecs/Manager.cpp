//
// Created by benajah on 4/15/24.
//
#include "Elementa/ecs/Manager.h"

namespace Elementa {
    unsigned int createEntity(Manager &manager) {
        manager.entities[manager.next_uid] = std::make_shared<Entity>();
        manager.entities[manager.next_uid]->uid = manager.next_uid;
        manager.next_uid++;
        return manager.next_uid - 1;
    }

    void addEntity(Manager &manager, const std::shared_ptr<Entity> &entity) {
        if (!manager.entities.contains(entity->uid)) {
            manager.entities[entity->uid] = entity;

            if (!entity->components.empty()) {
                for (std::pair<int, std::shared_ptr<Component>> pair: entity->components) {
                    manager.entities_by_component[pair.first].push_back(entity->uid);
                }
            }
        }
    }

    void removeEntity(Manager &manager, unsigned int entity_uid) {
        std::shared_ptr<Entity> entity = std::move(manager.entities[entity_uid]);

        for (std::pair<int, std::shared_ptr<Component>> pair: entity->components) {
            auto list = manager.entities_by_component[pair.first];
            for (auto it = list.begin(); it != list.end();) {
                if (*it == entity_uid) {
                    list.erase(it);
                    break;
                }
            }
        }

        manager.entities.erase(entity_uid);
    }

    void removeEntity(Manager &manager, std::shared_ptr<Entity> &entity) {
        removeEntity(manager, entity->uid);
    }

    std::shared_ptr<Entity> getEntityByUID(Manager &manager, unsigned int entity_uid) {
        if (manager.entities.contains(entity_uid))
            return manager.entities[entity_uid];
        else
            return nullptr;
    }

}