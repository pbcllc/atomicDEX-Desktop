/******************************************************************************
 * Copyright © 2013-2021 The Komodo Platform Developers.                      *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * Komodo Platform software, including this file may be copied, modified,     *
 * propagated or distributed except according to the terms contained in the   *
 * LICENSE file                                                               *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

//! Deps
#include <nlohmann/json.hpp>

//! Project Headers
#include "atomicdex/api/mm2/generics.hpp"
#include "atomicdex/api/mm2/rpc.best.orders.hpp"

//! Implementation RPC [best_orders]
namespace mm2::api
{
    void
    to_json(nlohmann::json& j, const best_orders_request& req)
    {
        j["coin"]   = req.coin;
        j["action"] = req.action;
        j["volume"] = req.volume;
    }

    void
    from_json(const nlohmann::json& j, best_order_infos& answer)
    {
        j.at("volume").get_to(answer.volume);
        j.at("price").get_to(answer.price);
        j.at("order_uuid").get_to(answer.order_uuid);
    }

    void
    from_json(const nlohmann::json& j, best_orders_answer_success& answer)
    {
        j.get_to(answer.result);
    }

    void
    from_json(const nlohmann::json& j, best_orders_answer& answer)
    {
        extract_rpc_json_answer<best_orders_answer_success>(j, answer);
    }

} // namespace mm2::api