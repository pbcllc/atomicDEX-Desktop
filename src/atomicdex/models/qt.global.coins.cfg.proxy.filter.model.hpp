/******************************************************************************
 * Copyright © 2013-2019 The Komodo Platform Developers.                      *
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

#pragma once

#include <QSortFilterProxyModel>

namespace atomic_dex
{
    class global_coins_cfg_proxy_model final : public QSortFilterProxyModel
    {
        Q_OBJECT

        bool     m_exclude_enabled_coins{false};
        CoinType m_type{CoinType::Size}; ///< if Size means no filter by type
        
        Q_PROPERTY(int length READ get_length NOTIFY lengthChanged)

      public:
        //! Constructor
        global_coins_cfg_proxy_model(QObject* parent);

        //! Destructor
        ~global_coins_cfg_proxy_model() noexcept final = default;

        //! QML API
        Q_INVOKABLE void filter_by_enableable() noexcept;
        Q_INVOKABLE void filter_by_type(CoinType type) noexcept;
        Q_INVOKABLE void set_all_state(bool checked) noexcept;


      protected:
        //! Override member functions
        bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override;
    
        bool lessThan(const QModelIndex& source_left, const QModelIndex& source_right) const final;
        
      private:
        //! Properties
        [[nodiscard]]
        int get_length() const noexcept;
        
      signals:
        void lengthChanged();
    };
} // namespace atomic_dex

Q_DECLARE_METATYPE(atomic_dex::global_coins_cfg_proxy_model*);